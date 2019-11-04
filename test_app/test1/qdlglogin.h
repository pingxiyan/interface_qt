#ifndef QDLGLOGIN_H
#define QDLGLOGIN_H

#include <QDialog>

namespace Ui {
class QDlgLogin;
}

class QDlgLogin : public QDialog
{
    Q_OBJECT

private:
    bool    m_moving=false; //表示窗口是否在鼠标操作下移动
    QPoint  m_lastPos;      //上一次的鼠标位置
    QString m_user="admin";  //初始化用户名
    QString m_pswd="123";     //初始化密码，未加密的
    int m_tryCount=0;       //试错次数
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public:
    explicit QDlgLogin(QWidget *parent = nullptr);
    ~QDlgLogin();

private slots:
    void on_bntOK_clicked();

    void on_bntCancel_clicked();

private:
    Ui::QDlgLogin *ui;
};

#endif // QDLGLOGIN_H
