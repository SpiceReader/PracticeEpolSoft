#ifndef TASK_H
#define TASK_H

// std
#include <string>
#include <vector>

// Implement task class
//
// Each task will have
// - id (unsinged int - individual number of task)
// - name
// - description
// - comments - std::vector<std::string> with comments
// - status - enum with values "OPEN, IN_PROGRESS, VERIFICATION, CLOSED"
//
// 1. Implement enum Status with values listed above
// 2. Implement above fields, provide getter and setter for each field (except vector of comments)
//    You can use setTaskName/getTaskName/mTaskName as an example
// 3. Implement methods addComment/getComments
class Task
{
public:
    /**
     * @brief Creates empty task
     */
    Task();

    /**
     * @return name of current task
     */
    const std::string getTaskName() const;

    /**
     * @brief sets name of current task
     * @param taskName name of current task
     */
    void setTaskName(const std::string& taskName);

    /**
     * @brief Adds comment to the current task
     * @param comment comment to add
     */
    void addComment(const std::string& comment);

    /**
     * @return all comments of the current task
     */
    std::vector<std::string> getComments();

private:
    std::string mTaskName;
    std::vector<std::string> mComments;
};

#endif // TASK_H
