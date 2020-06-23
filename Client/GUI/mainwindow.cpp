#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_saveButton_clicked()
{

}

void MainWindow::on_clearButton_clicked()
{
    ui->taskName->setText("");
    ui->taskDescription->setText("");
}
