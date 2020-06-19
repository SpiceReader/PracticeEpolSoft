#ifndef DBAPI_H
#define DBAPI_H

#include <TaskHandler/Task.h>

#include <QSqlDatabase>
#include <QSqlQuery>

class DbApi
{
    static QSqlDatabase db;
    static bool isOpen;
public:
    DbApi();
    bool static openDb(QString pathToDb);
    bool static closeDb();
    bool static isOpened() { return isOpen; };
    bool static insertTask(const Task& task);
    bool static deleteTaskById(unsigned int id);
    bool static updateTask(const Task& task);
};

#endif // DBAPI_H
