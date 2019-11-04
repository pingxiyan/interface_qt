#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDir"
#include "QFileDialog"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
//    QFont font=ui->QTextEdit->font();
//        font.setUnderline(checked);
//        ui->txtEdit->setFont(font);
    QString curPath=QDir::currentPath();

    QString aFileName=QFileDialog::getSaveFileName(this,tr("Choose save file"),curPath,"binary data(*.dat)");
    if (aFileName.isEmpty()) {
        return;
    }
    else {
        QMessageBox::information(this,"Tips","Save success!");
    }
}

void MainWindow::on_chkBoxUnder_clicked(bool checked)
{
    QFont font=ui->txtEdit->font();
    font.setUnderline(checked);
    ui->txtEdit->setFont(font);
}

void MainWindow::on_chkBoxItalic_clicked(bool checked)
{
    QFont font=ui->txtEdit->font();
    font.setItalic(checked);
    ui->txtEdit->setFont(font);
}

void MainWindow::on_chkBoxBold_clicked(bool checked)
{
    QFont font=ui->txtEdit->font();
    font.setBold(checked);
    ui->txtEdit->setFont(font);
}

void MainWindow::on_rBtnBlack_clicked(bool checked)
{
    QPalette plet=ui->txtEdit->palette();
    if (ui->rBtnBlack->isChecked())
            plet.setColor(QPalette::Text,Qt::black);
}

void MainWindow::on_rBtnRed_clicked(bool checked)
{
    QPalette plet=ui->txtEdit->palette();
    if (ui->rBtnRed->isChecked())
            plet.setColor(QPalette::Text,Qt::red);
}

void MainWindow::on_rBtnBlue_clicked(bool checked)
{
    QPalette plet=ui->txtEdit->palette();
    if (ui->rBtnBlue->isChecked())
            plet.setColor(QPalette::Text,Qt::blue);
}
