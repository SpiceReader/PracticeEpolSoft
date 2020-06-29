#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../TaskHandler/SingletonTaskHandler.h"
#include "Task/Task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_saveButton_clicked();

    void on_clearButton_clicked();

    void on_buttonConnectionServer_clicked();

private:
    Ui::MainWindow *ui;
    bool isRadiosChecked();
    void clearLayout(QLayout *layout, int numWidget);
};
#endif // MAINWINDOW_H
