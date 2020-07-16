#ifndef DIALOGCONNECTION_H
#define DIALOGCONNECTION_H

#include <QDialog>
#include "MessageHandler/MessageHandler.h"

namespace Ui {
class DialogConnection;
}

class DialogConnection : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnection(QWidget *parent = nullptr);
    ~DialogConnection();

private:
    Ui::DialogConnection *ui;

private slots:
    void buttonEnabled();
    void on_buttonOk_clicked();
};

#endif // DIALOGCONNECTION_H
