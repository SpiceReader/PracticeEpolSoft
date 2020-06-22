#ifndef DBAPI_H
#define DBAPI_H

#include <TaskHandler/Task.h>

#include <QtSql>

/**
 * @brief Provides single access to database
 */
class DbApi
{
    static QSqlDatabase db;
    static bool isOpen;
    DbApi() = default;
public:
    /**
     * @brief Open single connection to database
     * @param pathToDb URI to database
     * @return true if database was opened or false otherwise
     */
    bool static openDb(QString pathToDb);

    /**
     * @brief Close connection to database
     */
    void static closeDb();

    /**
     * @brief Checking if database was opened or not
     * @return true if database is opened or false otherwise
     */
    bool static isOpened() { return isOpen; };

    /**
     * @brief Get task from database
     * @param id Id of getted task
     * @return task from database
     */
    static Task* getTaskById(unsigned int id);

    /**
     * @brief Insert task to database
     * @param task Inserted task
     * @return true if task was added or false otherwise
     */
    bool static insertTask(const Task& task);

    /**
     * @brief Delete task from database by provided id
     * @param id Id of deleted task
     */
    void static deleteTaskById(unsigned int id);

    /**
     * @brief Delete all tasks from database
     */
    void static deleteAllTasks();

    /**
     * @brief Update task in database
     * @param task Updated task
     * @return true if task was updated or false otherwise
     */
    bool static updateTask(const Task& task);

    /**
     * @brief Insert comment to database
     * @param task Task in which will be saved comment
     * @param comment Saved comment
     * @return true if comment was added or false otherwise
     */
    bool static insertComment(const Task& task, std::string comment);

    /**
     * @brief Delete comment from database by provided id
     * @param id Id of deleted comment
     */
    void static deleteCommentById(unsigned int id);

    /**
     * @brief Delete all comments from database
     */
    void static deleteAllComments();

    /**
     * @brief Delete all comments from task from database
     * @param id_task Id of task where we want to delete all comments
     */
    void static deleteAllCommentsInTask(unsigned int id_task);
};

#endif // DBAPI_H
