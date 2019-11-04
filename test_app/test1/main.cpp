#include "mainwindow.h"
#include <QApplication>
#include "QTextCodec"
#include "qdlglogin.h"

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec); //解决汉字乱码问题

    QApplication a(argc, argv);

    QDlgLogin *dlgLogin=new QDlgLogin;
    if (dlgLogin->exec()==QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else {
        return  0;
    }
}
