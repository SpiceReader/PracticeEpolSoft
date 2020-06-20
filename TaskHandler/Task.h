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

    enum Status {OPEN = 1, IN_PROGRESS, VERIFICATION, CLOSED};
    /**
     * @brief Creates empty task
     */
    Task();

    /**
     * @return ID of current task
     */
    unsigned int getTaskId() const;

    /**
     * @brief sets ID of current task
     * @param taskId ID to be set
     */
    void setTaskId(unsigned int taskId);

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

    /**
     * @brief Adds description to the current task
     * @param description to add
     */
    void setTaskDescription(const std::string& description);

    const std::string getTaskDescription();

    void setTaskStatus(Status stat);

    Status getTaskStatus();

private:
    unsigned int mTaskId;
    std::string mTaskName;
    std::string mTaskDescription;
    std::vector<std::string> mComments;
    Status mTaskStatus;
};

#endif // TASK_H
