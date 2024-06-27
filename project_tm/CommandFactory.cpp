#include "CommandFactory.h"
#include "RegisterCommand.h"
#include "LoginCommand.h"
#include "AddTaskCommand.h"
#include "ListTasksCommand.h"
#include "UpdateTaskNameCommand.h"
#include "StartTaskCommand.h"
#include "UpdateTaskDescrCommand.h"
#include "AddTaskToDashBoardCommand.h"
#include "RemoveTaskFromDashBoardCommand.h"
#include "ListDashBoardCommand.h"
#include "DeleteTaskCommand.h"
#include "GetTaskCommand.h"
#include "ListCompletedTasksCommand.h"
#include "FinishTaskCommand.h"
#include "LogoutCommand.h"
#include "ExitCommand.h"
#include "AddCollaborationCommand.h"
#include "DeleteCollaborationCommand.h"
#include "ListCollaborationCommand.h"
#include "AddUserToCollaborationCommand.h"
#include "AssignTaskCommand.h"
#pragma warning (disable:4996)

const char* registerCommand = "register";
const size_t registerCommandSize = 8;

const char* loginCommand = "login";
const size_t loginCommandSize = 5;

const char* addTaskCommand = "add-task";
const size_t addTaskCommandSize = 8;

const char* listTaskCommand = "list-tasks";
const size_t listTaskCommandSize = 10;

const char* updateTaskNameCommand = "update-task-name";
const size_t updateTaskNameCommandSize = 16;

const char* startTaskCommand = "start-task";
const size_t startTaskCommandSize = 10;

const char* updateTaskDescriptionCommand = "update-task-description";
const size_t updateTaskDescriptionCommandSize = 23;

const char* addTaskToDashboardCommand = "add-task-to-dashboard";
const size_t addTaskToDashboardCommandSize = 21;

const char* removeTaskToDashboardCommand = "remove-task-from-dashboard";
const size_t removeTaskToDashboardCommandSize = 26;

const char* listDashboardCommand = "list-dashboard";
const size_t listDashboardCommandSize = 14;

const char* deleteTaskCommand = "delete-task";
const size_t deleteTaskCommandSize = 11;

const char* getTaskCommand = "get-task";
const size_t getTaskCommandSize = 8;

const char* listCompletedTasksCommand = "list-completed-tasks";
const size_t listCompletedTasksCommandSize = 20;

const char* finishTaskCommand = "finish-task";
const size_t finishTaskCommandSize = 11;

const char* logoutCommand = "logout";
const size_t logoutCommandSize = 6;

const char* exitCommand = "exit";
const size_t exitCommandSize = 4;

const char* addCollaborationCommand = "add-collaboration";
const size_t addCollaborationCommandSize = 17;

const char* deleteCollaborationCommand = "delete-collaboration";
const size_t deleteCollaborationCommandSize = 20;

const char* listCollaborationsCommand = "list-collaborations";
const size_t listCollaborationsCommandSize = 19;

const char* addUserToCollaborationCommand = "add-user";
const size_t addUserToCollaborationCommandSize = 8;

const char* assignTaskCommand = "assign-task";
const size_t assignTaskCommandSize = 11;

enum class CommandType
{
    REGISTER,
    LOGIN,
    ADD_TASK,
    LIST_TASKS,
    UPDATE_TASK_NAME,
    START_TASK,
    UPDATE_TASK_DESCRIPTION,
    ADD_TASK_TO_DASHBOARD,
    REMOVE_TASK_FROM_DASHBOARD,
    LIST_DASHBOARD,
    DELETE_TASK,
    GET_TASK,
    LIST_COMPLETED_TASKS,
    FINISH_TASK,
    LOGOUT,
    EXIT,
    ADD_COLLABORATION,
    DELETE_COLLABORATION,
    LIST_COLLABORATIONS,
    ADD_USER,
    ASSIGN_TASK
};

static bool isDigit(char ch)
{
    return (ch - '0' >= 0 && ch - '0' <= 9);
}

static bool isNumber(const MyString& str)
{
    int index = 0;
    while (str[index] != '\0' && index < str.getSize())
    {
        if (!isDigit(str[index++]))
            return false;
    }
    return true;
}

static CommandType identifyCommand(const MyString& str)
{
    if (str.substr(0, registerCommandSize) == registerCommand)
    {
        return CommandType::REGISTER;
    }
    else if (str.substr(0, loginCommandSize) == loginCommand)
    {
        return CommandType::LOGIN;
    }
    else if (str.substr(0, addTaskToDashboardCommandSize) == addTaskToDashboardCommand)
    {
        return CommandType::ADD_TASK_TO_DASHBOARD;
    }
    else if (str.substr(0, addTaskCommandSize) == addTaskCommand)
    {
        return CommandType::ADD_TASK;
    }
    else if (str.substr(0, listTaskCommandSize) == listTaskCommand)
    {
        return CommandType::LIST_TASKS;
    }
    else if (str.substr(0, updateTaskNameCommandSize) == updateTaskNameCommand)
    {
        return CommandType::UPDATE_TASK_NAME;
    }
    else if (str.substr(0, startTaskCommandSize) == startTaskCommand)
    {
        return CommandType::START_TASK;
    }
    else if (str.substr(0, updateTaskDescriptionCommandSize) == updateTaskDescriptionCommand)
    {
        return CommandType::UPDATE_TASK_DESCRIPTION;
    }
    else if (str.substr(0, removeTaskToDashboardCommandSize) == removeTaskToDashboardCommand)
    {
        return CommandType::REMOVE_TASK_FROM_DASHBOARD;
    }
    else if (str.substr(0, listDashboardCommandSize) == listDashboardCommand)
    {
        return CommandType::LIST_DASHBOARD;
    }
    else if (str.substr(0, deleteTaskCommandSize) == deleteTaskCommand)
    {
        return CommandType::DELETE_TASK;
    }
    else if (str.substr(0, getTaskCommandSize) == getTaskCommand)
    {
        return CommandType::GET_TASK;
    }
    else if (str.substr(0, listCompletedTasksCommandSize) == listCompletedTasksCommand)
    {
        return CommandType::LIST_COMPLETED_TASKS;
    }
    else if (str.substr(0, finishTaskCommandSize) == finishTaskCommand)
    {
        return CommandType::FINISH_TASK;
    }
    else if (str.substr(0, logoutCommandSize) == logoutCommand)
    {
        return CommandType::LOGOUT;
    }
    else if (str.substr(0, exitCommandSize) == exitCommand)
    {
        return CommandType::EXIT;
    }
    else if (str.substr(0, addCollaborationCommandSize) == addCollaborationCommand)
    {
        return CommandType::ADD_COLLABORATION;
    }
    else if (str.substr(0, deleteCollaborationCommandSize) == deleteCollaborationCommand)
    {
        return CommandType::DELETE_COLLABORATION;
    }
    else if (str.substr(0, listCollaborationsCommandSize) == listCollaborationsCommand)
    {
        return CommandType::LIST_COLLABORATIONS;
    }
    else if (str.substr(0, addUserToCollaborationCommandSize) == addUserToCollaborationCommand)
    {
        return CommandType::ADD_USER;
    }
    else if (str.substr(0, assignTaskCommandSize) == assignTaskCommand)
    {
        return CommandType::ASSIGN_TASK;
    }
}

static Command* makeRegisterCommand(const MyString& str, TaskManager& tm)
{
    //user123 123
    MyString username;
    MyString password;
    unsigned index = 0;

    while (str[index] != ' ')
    {
        username += str[index++];
    }
    index++;
    while (index < str.getSize())
    {
        password += str[index++];
    }
    
    return new RegisterCommand(tm, std::move(username), std::move(password));
}

static Command* makeLoginCommand(TaskManager& tm, const MyString& str)
{
    MyString username;
    MyString password;
    unsigned index = 0;

    while (str[index] != ' ')
    {
        username += str[index++];
    }
    index++;
    while (index < str.getSize())
    {
        password += str[index++];
    }

    return new LoginCommand(tm, std::move(username), std::move(password));
}

static Command* makeAddTaskCommand(TaskManager& tm, const MyString& str)
{
    MyString taskName;
    MyString dueDate;
    MyString description;
    unsigned index = 0;

    while (str[index] != ' ')
    {
        taskName += str[index++];
    }
    index++;
    while (str[index] != ' ')
    {
        dueDate += str[index++];
    }
    index++;

    while (index < str.getSize())
    {
        description += str[index++];
    }

    return new AddTaskCommand(tm, std::move(taskName), Date(std::move(dueDate)), std::move(description));
}

static Command* makeListTaskCommand(TaskManager& tm, const MyString& str)
{
    if (str.getSize() == 0)
    {
        return new ListTasksCommand(tm);
    }
    MyString dueDate;
    unsigned index = 1; // da ne hvashtame praznoto mqsto
    
    while (index < str.getSize())
    {
        dueDate += str[index++];
    }
    Date date(std::move(dueDate));

    return new ListTasksCommand(tm, Optional<Date>(std::move(date)));
}

static Command* makeUpdateTaskNameCommand(TaskManager& tm, const MyString& str)
{
    MyString idStr;
    MyString newtaskName;

    unsigned index = 0;
    while (str[index] != ' ')
        idStr += str[index++];

    index++;

    while (index < str.getSize())
        newtaskName += str[index++];

    unsigned id = atoi(idStr.c_str());

    return new UpdateTaskNameCommand(tm, id, std::move(newtaskName));
}

static Command* makeStartTaskCommand(TaskManager& tm, const MyString& str)
{
    MyString idStr;

    unsigned index = 0;
    while (index < str.getSize())
    {
        idStr += str[index++];
    }

    unsigned id = atoi(idStr.c_str());

    return new StartTaskCommand(tm, id);
}

static Command* makeUpdateTaskDescriptionCommand(TaskManager& tm, const MyString& str)
{
    MyString idStr;
    MyString desc;

    unsigned index = 0;
    while (str[index] != ' ')
        idStr += str[index++];

    index++;

    while (index < str.getSize())
        desc += str[index++];

    unsigned id = atoi(idStr.c_str());

    return new UpdateTaskDescrCommand(tm, id, std::move(desc));
}

static Command* makeAddTaskToDashboardCommand(TaskManager& tm, const MyString& str)
{
    MyString idStr;

    unsigned index = 0;
    while (index < str.getSize())
    {
        idStr += str[index++];
    }

    unsigned id = atoi(idStr.c_str());
    return new AddTaskToDashBoardCommand(tm, id);
}

static Command* makeRemoveTaskFromDashboardCommand(TaskManager& tm, const MyString& str)
{
    MyString idStr;

    unsigned index = 0;
    while (index < str.getSize())
    {
        idStr += str[index++];
    }

    unsigned id = atoi(idStr.c_str());
    return new RemoveTaskFromDashBoardCommand(tm, id);
}

static Command* makeListDashboard(TaskManager& tm, const MyString& str)
{
    return new ListDashBoardCommand(tm);
}

static Command* makeDeleteTaskCommand(TaskManager& tm, const MyString& str)
{
    MyString idStr;

    unsigned index = 0;
    while (index < str.getSize())
    {
        idStr += str[index++];
    }

    unsigned id = atoi(idStr.c_str());
    return new DeleteTaskCommand(tm, id);
}

static Command* makeGetTaskCommand(TaskManager& tm, const MyString& str)
{
    
    if (isNumber(str))
    {
        MyString idStr;

        unsigned index = 0;
        while (index < str.getSize())
        {
            idStr += str[index++];
        }

        unsigned id = atoi(idStr.c_str());
        return new GetTaskCommand(tm, id);
    }

    MyString taskName = str;
    return new GetTaskCommand(tm, std::move(taskName));
}

static Command* makeListCompletedTaskCommand(TaskManager& tm, const MyString& str)
{
    return new ListCompletedTasksCommand(tm);
}

static Command* makeFinishTaskCommand(TaskManager& tm, const MyString& str)
{
    MyString idStr;

    unsigned index = 0;
    while (index < str.getSize())
    {
        idStr += str[index++];
    }

    unsigned id = atoi(idStr.c_str());

    return new FinishTaskCommand(tm, id);
}

static Command* makeLogoutCommand(TaskManager& tm, const MyString& str)
{
    return new LogoutCommand(tm);
}

static Command* makeExitCommand(TaskManager& tm, const MyString& str)
{
    return new ExitCommand(tm);
}

static Command* makeAddCollaborationCommand(TaskManager& tm, const MyString& str)
{
    MyString collabName;
    unsigned index = 0;
    while (index < str.getSize())
    {
        collabName += str[index++];
    }

    return new AddCollaborationCommand(tm, std::move(collabName));
}

static Command* makeListCollaborationCommand(TaskManager& tm, const MyString& str)
{
    return new ListCollaborationCommand(tm);
}

static Command* makeAddUserCommand(TaskManager& tm, const MyString& str)
{
    MyString collabName;
    MyString username;

    unsigned index = 0;
    while (str[index] != ' ')
    {
        collabName += str[index++];
    }
    index++;

    while (index < str.getSize())
    {
        username += str[index++];
    }

    return new AddUserToCollaborationCommand(tm, std::move(collabName), std::move(username));

}

static Command* makeAssignTaskCommand(TaskManager& tm, const MyString& str)
{
    MyString collabName;
    MyString username;
    MyString taskName;
    MyString dueDate;
    MyString description;

    unsigned index = 0;
    while (str[index] != ' ')
    {
        collabName += str[index++];
    }
    index++;

    while (str[index] != ' ')
    {
        username += str[index++];
    }
    index++;

    while (str[index] != ' ')
    {
        taskName += str[index++];
    }
    index++;

    while (str[index] != ' ')
    {
        dueDate += str[index++];
    }
    index++;

    while (index < str.getSize())
    {
        description += str[index++];
    }

    return new AssignTaskCommand(tm, std::move(collabName), std::move(username), std::move(taskName), Date(std::move(dueDate)), std::move(description));
}

Command* CommandFactory::makeCommand(TaskManager& tm, const MyString& str)
{
    CommandType type;
    type = identifyCommand(str);

    switch (type)
    {
        case CommandType::REGISTER:
        {
            return makeRegisterCommand(str.substr(registerCommandSize + 1, str.getSize() - registerCommandSize + 1), tm);
        }
        case CommandType::LOGIN:
        {
            return makeLoginCommand(tm, str.substr(loginCommandSize + 1, str.getSize() - loginCommandSize + 1));
        }
        case CommandType::ADD_TASK:
        {
            return makeAddTaskCommand(tm, str.substr(addTaskCommandSize + 1, str.getSize() - addTaskCommandSize + 1));
        }
        case CommandType::LIST_TASKS:
        {
            return makeListTaskCommand(tm, str.substr(listTaskCommandSize, str.getSize() - listTaskCommandSize));
        }
        case CommandType::UPDATE_TASK_NAME:
        {
            return makeUpdateTaskNameCommand(tm, str.substr(updateTaskNameCommandSize + 1, str.getSize() - updateTaskNameCommandSize + 1));
        }
        case CommandType::START_TASK:
        {
            return makeStartTaskCommand(tm, str.substr(startTaskCommandSize + 1, str.getSize() - startTaskCommandSize + 1));
        }
        case CommandType::UPDATE_TASK_DESCRIPTION:
        {
            return makeUpdateTaskDescriptionCommand(tm, str.substr(updateTaskDescriptionCommandSize + 1, str.getSize() - updateTaskDescriptionCommandSize + 1));
        }
        case CommandType::ADD_TASK_TO_DASHBOARD:
        {
            return makeAddTaskToDashboardCommand(tm, str.substr(addTaskToDashboardCommandSize + 1, str.getSize() - addTaskToDashboardCommandSize + 1));
        }
        case CommandType::REMOVE_TASK_FROM_DASHBOARD:
        {
            return makeRemoveTaskFromDashboardCommand(tm, str.substr(removeTaskToDashboardCommandSize + 1, str.getSize() - removeTaskToDashboardCommandSize + 1));
        }
        case CommandType::LIST_DASHBOARD:
        {
            return makeListDashboard(tm, str.substr(listDashboardCommandSize, str.getSize() - listDashboardCommandSize));
        }
        case CommandType::DELETE_TASK:
        {
            return makeDeleteTaskCommand(tm, str.substr(deleteTaskCommandSize + 1, str.getSize() - deleteTaskCommandSize + 1));
        }
        case CommandType::GET_TASK:
        {
            return makeGetTaskCommand(tm, str.substr(getTaskCommandSize + 1, str.getSize() - getTaskCommandSize + 1));
        }
        case CommandType::LIST_COMPLETED_TASKS:
        {
            return makeListCompletedTaskCommand(tm, str.substr(listCompletedTasksCommandSize, str.getSize() - listCompletedTasksCommandSize));
        }
        case CommandType::FINISH_TASK:
        {
            return makeFinishTaskCommand(tm, str.substr(finishTaskCommandSize + 1, str.getSize() - finishTaskCommandSize + 1));
        }
        case CommandType::LOGOUT:
        {
            return makeLogoutCommand(tm, str.substr(logoutCommandSize, str.getSize() - logoutCommandSize));
        }
        case CommandType::EXIT:
        {
            return makeExitCommand(tm, str.substr(exitCommandSize, str.getSize() - exitCommandSize));
        }
        case CommandType::ADD_COLLABORATION:
        {
            return makeAddCollaborationCommand(tm, str.substr(addCollaborationCommandSize + 1, str.getSize() - addCollaborationCommandSize + 1));
        }
        case CommandType::LIST_COLLABORATIONS:
        {
            return makeListCollaborationCommand(tm, str.substr(listCollaborationsCommandSize, str.getSize() - listCollaborationsCommandSize));
        }
        case CommandType::ADD_USER:
        {
            return makeAddUserCommand(tm, str.substr(addUserToCollaborationCommandSize + 1, str.getSize() - addUserToCollaborationCommandSize + 1));
        }
        case CommandType::ASSIGN_TASK:
        {
            return makeAssignTaskCommand(tm, str.substr(assignTaskCommandSize + 1, str.getSize() - assignTaskCommandSize + 1));
        }
    }
}
