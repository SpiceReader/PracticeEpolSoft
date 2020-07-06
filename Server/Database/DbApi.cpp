#include "DbApi.h"

bool DbApi::isOpen = false;
QSqlDatabase DbApi::db = QSqlDatabase::addDatabase("QSQLITE");
std::map<Task::Status, std::string> DbApi::enumStatusToStringStatus {{Task::OPEN, "OPEN"},
                                                                     {Task::IN_PROGRESS, "IN_PROGRESS"},
                                                                     {Task::VERIFICATION, "VERIFICATION"},
                                                                     {Task::CLOSED, "CLOSED"}};

std::map<std::string, Task::Status> DbApi::stringStatusToEnumStatus {{"OPEN", Task::OPEN},
                                                                     {"IN_PROGRESS", Task::IN_PROGRESS},
                                                                     {"VERIFICATION", Task::VERIFICATION},
                                                                     {"CLOSED", Task::CLOSED}};


bool DbApi::openDb(QString pathToDb){
    if(isOpen)
        db.close();

    db.setDatabaseName(pathToDb);
    isOpen = (db.open()) ? true : false;

    if(!isOpen){
        qDebug() << "all is bad";
        return false;
    }

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
        "\"id_task\"	INTEGER NOT NULL,"
        "\"comment\"	TEXT NOT NULL,"
        "FOREIGN KEY(\"id_task\") REFERENCES \"task\"(\"id\") ON DELETE CASCADE,"
        "PRIMARY KEY(\"id\" AUTOINCREMENT)"
    ");";
    query.prepare(queryStr);
    query.exec();
    return true;
}

void DbApi::closeDb(){
    db.close();
}

Task* DbApi::getTaskById(unsigned int id){
    if(!isOpened())
        return nullptr;

    QSqlQuery query(nullptr, db);
    QString queryStr = "SELECT * FROM task WHERE id=%1;";
    Task *gettedTask = new Task();

    queryStr = queryStr.arg(id);
    query.exec(queryStr);
    QSqlRecord rec = query.record();

    while(query.next()){
        gettedTask->setTaskId(query.value(rec.indexOf("id")).toUInt());
        gettedTask->setTaskName(query.value(rec.indexOf("name")).toString().toStdString());
        gettedTask->setTaskDescription(query.value(rec.indexOf("description")).toString().toStdString());

        std::string taskStatus = query.value(rec.indexOf("status")).toString().toStdString();
        gettedTask->setTaskStatus(stringStatusToEnumStatus[taskStatus]);
    }

    return gettedTask;
}

std::vector<Task> DbApi::getAllTasks()
{
    std::vector<Task> vectorOfTasks;
    if(!isOpened())
        return vectorOfTasks;

    QSqlQuery query;
    QString queryStr = "SELECT * FROM task;";

    query.exec(queryStr);
    Task gettedTask;
    QSqlRecord rec = query.record();

    while(query.next()){
        gettedTask.setTaskId(query.value(rec.indexOf("id")).toUInt());
        gettedTask.setTaskName(query.value(rec.indexOf("name")).toString().toStdString());
        gettedTask.setTaskDescription(query.value(rec.indexOf("description")).toString().toStdString());

        std::string taskStatus = query.value(rec.indexOf("status")).toString().toStdString();
        gettedTask.setTaskStatus(stringStatusToEnumStatus[taskStatus]);

        vectorOfTasks.push_back(gettedTask);
    }

    return vectorOfTasks;
}

bool DbApi::insertTask(const Task &task){
    if(!isOpened())
        return false;

    QSqlQuery query;
    QString queryStr = "INSERT INTO task(name, description, status) "
                "VALUES ('%1', '%2', '%3');";

    queryStr = queryStr.arg(task.getTaskName().c_str());
    queryStr = queryStr.arg(task.getTaskDescription().c_str());
    queryStr = queryStr.arg(DbApi::enumStatusToStringStatus[task.getTaskStatus()].c_str());

    query.prepare(queryStr);
    return query.exec();
}

bool DbApi::updateTask(const Task &task){
    if(!isOpened())
        return false;

    QSqlQuery query;
    QString queryStr = "UPDATE task SET name='%1', description='%2', status='%3' WHERE id=%4;";

    queryStr = queryStr.arg(task.getTaskName().c_str());
    queryStr = queryStr.arg(task.getTaskDescription().c_str());
    queryStr = queryStr.arg(DbApi::enumStatusToStringStatus[task.getTaskStatus()].c_str());
    queryStr = queryStr.arg(task.getTaskId());

    query.prepare(queryStr);
    return query.exec();
}

void DbApi::deleteTaskById(unsigned int id){
    if(!isOpened())
        return;

    QSqlQuery query;
    QString queryStr = "DELETE FROM task WHERE id=%1;";

    queryStr = queryStr.arg(id);

    query.prepare(queryStr);
    query.exec();
}

void DbApi::deleteAllTasks(){
    if(!isOpened())
        return;

    QSqlQuery query;
    QString queryStr = "DELETE FROM task;";

    query.prepare(queryStr);
    query.exec();
}

bool DbApi::insertComment(const Task &task, std::string comment){
    if(!isOpened())
        return false;

    QSqlQuery query;
    QString queryStr = "INSERT INTO comment(id_task, comment) "
                "VALUES (%1, '%2');";

    queryStr = queryStr.arg(task.getTaskId());
    queryStr = queryStr.arg(comment.c_str());

    query.prepare(queryStr);
    return query.exec();
}

void DbApi::deleteCommentById(unsigned int id){
    if(!isOpened())
        return;

    QSqlQuery query;
    QString queryStr = "DELETE FROM comment WHERE id=%1;";

    queryStr = queryStr.arg(id);

    query.prepare(queryStr);
    query.exec();
}

void DbApi::deleteAllComments(){
    if(!isOpened())
        return;

    QSqlQuery query;
    QString queryStr = "DELETE FROM comment;";

    query.prepare(queryStr);
    query.exec();
}

void DbApi::deleteAllCommentsInTask(unsigned int id_task){
    if(!isOpened())
        return;

    QSqlQuery query;
    QString queryStr = "DELETE FROM comment WHERE id_task=%1;";

    queryStr = queryStr.arg(id_task);

    query.prepare(queryStr);
    query.exec();
}
