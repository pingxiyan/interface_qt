#include "qdlglogin.h"
#include "ui_qdlglogin.h"
#include "qlabel.h"
#include"QLineEdit"
#include "QMessageBox"
#include "QEvent"
#include "QMouseEvent"

QDlgLogin::QDlgLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QDlgLogin)
{
    ui->setupUi(this);

    ui->editPSWD->setText("123");
    ui->editUsername->setText("admin");

    ui->editPSWD->setEchoMode(QLineEdit::Password); //密码输入编辑框设置为密码输入模式
    this->setAttribute(Qt::WA_DeleteOnClose);//设置为关闭时删除
    this->setWindowFlags(Qt::SplashScreen); //设置为SplashScreen, 窗口无边框,不在任务栏显示
    //this->setWindowFlags(Qt::FramelessWindowHint);//无边框，但是在任务显示对话框标题

}

QDlgLogin::~QDlgLogin()
{
    delete ui;
}

void QDlgLogin::on_bntOK_clicked()
{
    QString user=ui->editUsername->text().trimmed();//输入用户名
    QString pswd=ui->editPSWD->text().trimmed(); //输入密码

    if ((user==m_user)&&(pswd==m_pswd)) //如果用户名和密码正确
    {
        //writeSettings();//保存设置
        this->accept(); //对话框 accept()，关闭对话框
    }
    else
    {
        m_tryCount++; //错误次数
        if (m_tryCount>3)
        {
            QMessageBox::critical(this, "错误", "输入错误次数太多，强行退出");
            this->reject(); //退出
        }
        else
            QMessageBox::warning(this, "错误提示", "用户名或密码错误");
    }
}

void QDlgLogin::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_moving = true;
        //记录下鼠标相对于窗口的位置
        //event->globalPos()鼠标按下时，鼠标相对于整个屏幕位置
        //pos() this->pos()鼠标按下时，窗口相对于整个屏幕位置
        m_lastPos = event->globalPos() - pos();
    }
    return QDialog::mousePressEvent(event);  //
}
void QDlgLogin::mouseMoveEvent(QMouseEvent *event)
{
    //(event->buttons() && Qt::LeftButton)按下是左键
    //鼠标移动事件需要移动窗口，窗口移动到哪里呢？就是要获取鼠标移动中，窗口在整个屏幕的坐标，然后move到这个坐标，怎么获取坐标？
    //通过事件event->globalPos()知道鼠标坐标，鼠标坐标减去鼠标相对于窗口位置，就是窗口在整个屏幕的坐标
    if (m_moving && (event->buttons() && Qt::LeftButton)
        && (event->globalPos()-m_lastPos).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos()-m_lastPos);
        m_lastPos = event->globalPos() - pos();
    }
    return QDialog::mouseMoveEvent(event);
}

void QDlgLogin::mouseReleaseEvent(QMouseEvent *event)
{//鼠标按键释放
    m_moving=false; //停止移动
}

void QDlgLogin::on_bntCancel_clicked()
{
    this->close();
}
