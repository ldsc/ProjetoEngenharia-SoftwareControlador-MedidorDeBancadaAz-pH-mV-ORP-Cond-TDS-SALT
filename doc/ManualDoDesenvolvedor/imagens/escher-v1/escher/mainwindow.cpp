#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "aboutwindow.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_about_clicked()
{
    About *dialog = new About;
    dialog->setWindowTitle("Dialog");
    dialog->show();
}

