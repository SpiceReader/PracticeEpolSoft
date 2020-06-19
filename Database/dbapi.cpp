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
        "\"status\"	TEXT DEFAULT 'OPEN' CHECK(status IN ('OPEN', 'IN_PROGRESS', 'VERIFICATION', 'CLOSED')),"
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
    QString queryStr = "INSERT INTO task(name, description, status) "
                "VALUES ('%1', '%2', '%3');";
    queryStr = queryStr.arg(task.getTaskName().c_str());
    //str_insert = str_insert.arg(task.getDescription().c_str());
    //str_insert = str_insert.arg(task.getStatus().c_str());
    query.prepare(queryStr);
    return query.exec();
}

bool DbApi::updateTask(const Task &task){
    QSqlQuery query;
    QString queryStr = "UPDATE task SET name='%1', description='%2', status='%3' WHERE id=%4;";
    queryStr = queryStr.arg(task.getTaskName().c_str());
    //queryStr = queryStr.arg(task.getDescription().c_str());
    //queryStr = queryStr.arg(task.getStatus().c_str());
    queryStr = queryStr.arg(task.getTaskId());
    query.prepare(queryStr);
    return query.exec();
}

void DbApi::deleteTaskById(unsigned int id){
    QSqlQuery query;
    QString queryStr = "DELETE FROM task WHERE id=%1;";
    queryStr = queryStr.arg(id);
    query.prepare(queryStr);
}

bool DbApi::insertComment(const Task &task, std::string comment){
    QSqlQuery query;
    QString queryStr = "INSERT INTO comment(id_task, comment) "
                "VALUES (%1, '%2');";
    queryStr = queryStr.arg(task.getTaskId());
    queryStr = queryStr.arg(comment.c_str());
    query.prepare(queryStr);
    return query.exec();
}

void DbApi::deleteCommentById(unsigned int id){
    QSqlQuery query;
    QString queryStr = "DELETE FROM comment WHERE id=%1;";
    queryStr = queryStr.arg(id);
    query.prepare(queryStr);
}
