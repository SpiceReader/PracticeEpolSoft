#include "dbapi.h"

bool DbApi::isOpen = false;
QSqlDatabase DbApi::db = QSqlDatabase::addDatabase("QSQLITE");

DbApi::DbApi()
{

}

bool DbApi::openDb(QString pathToDb){
    if(isOpen)
        db.close();

    db.setDatabaseName(pathToDb);
    isOpen = (db.open()) ? true : false;

    if(!isOpen)
        return false;

    QString queryStr("CREATE TABLE IF NOT EXISTS \"task\" ("
        "\"id\"	INTEGER NOT NULL UNIQUE,"
        "\"name\"	TEXT NOT NULL,"
        "\"description\"	TEXT,"
        "\"status\"	TEXT CHECK(status IN ('OPEN', 'IN_PROGRESS', 'VERIFICATION', 'CLOSED')),"
        "PRIMARY KEY(\"id\" AUTOINCREMENT)"
    ");");

    QSqlQuery query;
    query.prepare(queryStr);
    query.exec();

    queryStr = "CREATE TABLE IF NOT EXISTS \"comment\" ("
        "\"id\"	INTEGER NOT NULL UNIQUE,"
        "\"id_task\"	INTEGER NOT NULL UNIQUE,"
        "\"comment\"	TEXT NOT NULL,"
        "FOREIGN KEY(\"id_task\") REFERENCES \"task\"(\"id\") ON DELETE CASCADE,"
        "PRIMARY KEY(\"id\" AUTOINCREMENT)"
    ");";
    query.prepare(queryStr);
    query.exec();
    return true;
}

bool DbApi::insertTask(const Task &task){
    QSqlQuery query;
    QString str_insert = "INSERT INTO tasks(name, description, status) "
                "VALUES ('%1', '%2', '%3');";
    str_insert = str_insert.arg(task.getTaskName().c_str());
    str_insert = str_insert.arg(task.getDescription().c_str());
    str_insert = str_insert.arg(task.getStatus().c_str());
    query.prepare(str_insert);
    return query.exec();
}
