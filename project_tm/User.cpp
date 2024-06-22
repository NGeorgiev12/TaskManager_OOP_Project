#include "User.h"
static Date getToday()
{
    std::time_t t = time(0);
    std::tm* now = std::localtime(&t);

    Date currentDay;
    currentDay.setYear(now->tm_year + 1900);
    currentDay.setMonth(now->tm_mon + 1);
    currentDay.setDay(now->tm_mday);
    return currentDay;
}
const MyString& User::getUsername() const
{
    return username;
}

const MyString& User::getPassword() const
{
    return password;
}

const DashBoard& User::getDashBoard() const
{
    return dashboard;

}

void User::setUsername(const MyString& newUsername)
{
    username = newUsername;
}

void User::setPassword(const MyString& newPassword)
{
    password = newPassword;
}

void User::addCollaborationTask(CollaborationTask* task)
{
    collabTasks.pushBack(task);
}

void User::addTask(Task&& task)
{
	tasks.pushBack(std::move(task));
}

void User::updateTaskName(unsigned id, MyString&& newName)
{
    unsigned index = findTaskIndexById(id);
    tasks[index].setTaskName(std::move(newName));
}

void User::startTask(unsigned id)
{
    unsigned index = findTaskIndexById(id);
    tasks[index].setStatus(Status::IN_PROCESS); 
    // to do-sushtoto i ot kolaboraciqta
}

void User::updateTaskDescription(unsigned id, MyString&& newDescription)
{
    unsigned index = findTaskIndexById(id);
    tasks[index].setDescription(std::move(newDescription));
}

void User::addTaskToDashBoard(unsigned id)
{
    dashboard.addTaskId(id);
}

bool User::isTaskInDashBoard(unsigned id) const
{
    for (int i = 0; i < dashboard.getTaskIds().getSize(); i++)
    {
        if (dashboard.getTaskIds()[i] == id)
            return true;
    }
    return false;
}

void User::removeTaskFromDashBoard(unsigned id)
{
    dashboard.removeTaskId(id);
}

void User::deleteTask(unsigned taskId)
{
    unsigned taskIndex = findTaskIndexById(taskId);
    tasks.erase(taskIndex);
}

void User::setTaskStatus(Status status, unsigned taskId)
{
    unsigned taskIndex = findTaskIndexById(taskId);
    tasks[taskIndex].setStatus(status);
}


const Vector<Task>& User::getTasks() const
{
	return tasks;
}

const Vector<MyString>& User::getCollabNames() const
{
    return collabTaskNames;
}

const Vector<CollaborationTask*>& User::getCollabTasksPtrs() const
{
    return collabTasks;
}

void User::saveUserInBinary(std::ofstream& ofs) const
{
    username.saveToBinary(ofs);
    password.saveToBinary(ofs);
    dashboard.saveToBinary(ofs);
    tasks.saveToBinary(ofs);
    collabTaskNames.saveToBinary(ofs);
}

void User::createDashBoard()
{
    if (dashboard.getCurrentDate() != getToday())
    {
        for (int i = 0; i < dashboard.getTaskIds().getSize(); i++)
        {
            setTaskStatus(dashboard.getTaskIds()[i], Status::OVERDUE);
        }

        dashboard.freeTaskIds();
        for (int i = 0; i < tasks.getSize(); i++)
        {
            if (tasks[i].isDueDateToday())
                dashboard.addTaskId(tasks[i].getId());
        }

        for (int i = 0; i < collabTasks.getSize(); i++)
        {
            if (collabTasks[i]->getDueDate() == getToday())
                dashboard.addTaskId(collabTasks[i]->getId());
            // priemame nagotovo che id-tata sa razlichni
        }
    }
}

void User::setTaskStatus(unsigned taskId, Status status)
{
    unsigned taskIndex = findTaskIndexById(taskId);
    tasks[taskIndex].setStatus(status);
}

void User::loadUserFromBinary(std::ifstream& ifs)
{

    username.loadFromBinary(ifs);

    password.loadFromBinary(ifs);

    dashboard.loadFromBinary(ifs);
    if (dashboard.getCurrentDate() != getToday())
    {
        dashboard.freeTaskIds();
        for (int i = 0; i < tasks.getSize(); i++)
        {
            if (tasks[i].isDueDateToday())
                dashboard.addTaskId(tasks[i].getId());
        }
    }
        

    tasks.loadFromBinary(ifs);
    collabTaskNames.loadFromBinary(ifs);
}

User::User(const MyString& username, const MyString& password, const DashBoard& dashboard, const Vector<Task>& tasks, const Vector<MyString> collabTaskNames) : dashboard(dashboard)
{
    this->username = username;
    this->password = password;

    this->tasks = tasks;
    this->collabTaskNames = collabTaskNames;
}

User::User(MyString&& username, MyString&& password)
{
    this->username = std::move(username);
    this->password = std::move(password);
}

bool User::isIdUnique(unsigned id) const
{
    for (int i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i].getId() == id)
            return false;
    }
    return true;
}

bool User::isCollabIdUnique(unsigned id) const
{
    for (int i = 0; i < collabTasks.getSize(); i++)
    {
        if (collabTasks[i]->getId() == id)
            return false;
    }
    return true;
}

unsigned User::findTaskIndexById(int id) const
{
    for (int i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i].getId() == id)
            return i;
    }

    throw std::invalid_argument("There is no such task!");
}

//void User::deleteTask(int id)
//{
//	if (isIdUnique(id))
//		throw std::invalid_argument("User::deleteTask There is no such taskId");
//
//	int taskIndex = findTaskIndexById(id);
//	tasks.erase(taskIndex);
//	regulateId();
//}

//void User::getTask(const MyString& name)
//{
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		if (tasks[i].getTaskName() == name)
//		{
//			printTask(tasks[i]);
//			return;
//			// id-тата нарастват последователно => ще се печата първото
//		}
//	}
//
//	throw std::invalid_argument("User::getTask Invalid taskName");
//}

//void User::getTask(int id)
//{
//	if (isIdUnique(id))
//		throw std::invalid_argument("User::getTaskById There is no such taskId");
//
//	int taskIndex = findTaskIndexById(id);
//	printTask(tasks[taskIndex]);
//}

//void User::listTasks(const Date& date)
//{
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		if (tasks[i].getDueDate() == date)
//			printTask(tasks[i]);
//	}
//}

//void User::listTasks()
//{
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		printTask(tasks[i]);
//	}
//}

//void User::listCompletedTasks()
//{
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		if (tasks[i].getStatus() == Status::DONE)
//			printTask(tasks[i]);
//	}
//}

//void User::finishTask(int id)
//{
//	int taskIndex = findTaskIndexById(id);
//	tasks[taskIndex].setStatus(Status::DONE);
//}

//
//void User::regulateId()
//{
//	if (tasks[0].getId() == MAX_INITIAL_ID)
//	{
//		for (int i = 0; i < tasks.getSize(); i++)
//		{
//			int newId = tasks[i].getId() - MAX_INITIAL_ID + 1;
//			tasks[i].setId(newId);
//		}
//	}
//		
//}



