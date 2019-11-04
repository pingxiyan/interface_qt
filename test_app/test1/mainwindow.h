#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_chkBoxUnder_clicked(bool checked);

    void on_chkBoxItalic_clicked(bool checked);

    void on_chkBoxBold_clicked(bool checked);

    void on_rBtnBlack_clicked(bool checked);

    void on_rBtnRed_clicked(bool checked);

    void on_rBtnBlue_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
