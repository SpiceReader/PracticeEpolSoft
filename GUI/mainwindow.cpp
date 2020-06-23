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
    if(ui->taskDescription->toPlainText().isEmpty() ||
            ui->taskName->text().isEmpty() ||
            !isRadiosChecked()) return;

    Task task;
    QString taskTitle = ui->taskName->text();
    QString taskDescription = ui->taskDescription->toPlainText();
    QGroupBox *taskBox = new QGroupBox(taskTitle);
    QLabel *LabelTaskDescription = new QLabel(taskDescription);
    QVBoxLayout *taskLayout = new QVBoxLayout;

    taskBox->setMinimumHeight(80);

    task.setTaskName(taskTitle.toStdString());
    task.setTaskDescription(ui->labelTaskDescription->text().toStdString());


    taskLayout->addWidget(LabelTaskDescription);

    taskBox->setLayout(taskLayout);
    LabelTaskDescription->setWordWrap(true);
    if(ui->radioOpen->isChecked()){
        ui->openTaskLayout->addWidget(taskBox);
        task.setTaskStatus(Task::OPEN);
    }
    if(ui->radioProcess->isChecked()){
        ui->proccesTaskLayout->addWidget(taskBox);
        task.setTaskStatus(Task::IN_PROGRESS);
    }

    if(ui->radioClosed->isChecked()){
        ui->closeTaskLayout->addWidget(taskBox);
        task.setTaskStatus(Task::CLOSED);
    }

    if(ui->radioVerification->isChecked()){
        ui->verTaskLayout->addWidget(taskBox);
        task.setTaskStatus(Task::VERIFICATION);
    }

    SingletonTaskHandler::getInstance()->addTask(task);
}

void MainWindow::on_clearButton_clicked()
{
    ui->taskName->setText("");
    ui->taskDescription->setText("");

    SingletonTaskHandler::getInstance()->clearTasks();

    clearLayout(ui->openTaskLayout, 2);
    clearLayout(ui->proccesTaskLayout, 2);
    clearLayout(ui->verTaskLayout, 2);
    clearLayout(ui->closeTaskLayout, 2);
}

void MainWindow::clearLayout(QLayout *layout, int numWidget){
    QLayoutItem *item;
        while((item = layout->takeAt(numWidget))) {
            if (item->layout()) {
                clearLayout(item->layout(), numWidget);
                delete item->layout();
            }
            if (item->widget()) {
               delete item->widget();
            }
            delete item;
        }
}

bool MainWindow::isRadiosChecked(){
    return (ui->radioOpen->isChecked() ||
            ui->radioClosed->isChecked() ||
            ui->radioVerification->isChecked() ||
            ui->radioProcess->isChecked());
}


