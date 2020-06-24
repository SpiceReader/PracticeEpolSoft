#include "dialogconnection.h"
#include "ui_dialogconnection.h"

DialogConnection::DialogConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnection)
{
    ui->setupUi(this);
    ui->buttonOk->setEnabled(false);
    //QLineEdit
    connect(ui->IpServer,SIGNAL(textChanged(QString)), this, SLOT(buttonEnabled()));
    connect(ui->numPort,SIGNAL(textChanged(QString)), this, SLOT(buttonEnabled()));

}

DialogConnection::~DialogConnection()
{
    delete ui;
}

void DialogConnection::buttonEnabled(){

    if(ui->numPort->text().isEmpty()||
        ui->IpServer->text().isEmpty())
        ui->buttonOk->setEnabled(false);
    else
        ui->buttonOk->setEnabled(true);
}

void DialogConnection::on_buttonOk_clicked()
{
    //set ip server and port
}
