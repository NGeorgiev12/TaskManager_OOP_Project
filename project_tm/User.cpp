﻿#include "User.h"
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
    int taskIndex = findTaskIndexById(id);
    int collabTaskIndex = findCollabTaskIndexById(id);

    if (taskIndex == -1 && collabTaskIndex == -1)
        throw std::invalid_argument("There is no such task!");

    if (taskIndex != -1)
        tasks[taskIndex].setTaskName(std::move(newName));
    else
        collabTasks[collabTaskIndex]->setTaskName(std::move(newName));
    
}

void User::updateTaskDescription(unsigned id, MyString&& newDescription)
{
    int taskIndex = findTaskIndexById(id);
    int collabTaskIndex = findCollabTaskIndexById(id);

    if (taskIndex == -1 && collabTaskIndex == -1)
        throw std::invalid_argument("There is no such task!");

    if (taskIndex != -1)
        tasks[taskIndex].setDescription(std::move(newDescription));
    else
        collabTasks[collabTaskIndex]->setDescription(std::move(newDescription));
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

bool User::isCollabTaskInDashBoard(unsigned id) const
{
    for (int i = 0; i < collabTasks.getSize(); i++)
    {
        if (collabTasks[i]->getId() == id)
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
    int taskIndex = findTaskIndexById(taskId);

    if (taskIndex == -1)
        throw std::invalid_argument("There is no such task!");

    tasks.erase(taskIndex);
    if (isTaskInDashBoard(tasks[taskIndex].getId()))
        dashboard.removeTaskId(tasks[taskIndex].getId());
    
}

void User::setTaskStatus(Status status, unsigned taskId)
{
    int taskIndex = findTaskIndexById(taskId);
    int collabTaskIndex = findCollabTaskIndexById(taskId);

    if (taskIndex == -1 && collabTaskIndex == -1)
        throw std::invalid_argument("There is no such task!");

    if (taskIndex != -1)
        tasks[taskIndex].setStatus(status);
    else
        collabTasks[collabTaskIndex]->setStatus(status);
}

void User::addCollabName(const MyString& collabName)
{
    if (!isCollabNameUnique(collabName))
        throw std::invalid_argument("There is already collaboration with this name!");
    collabNames.pushBack(collabName);
}

void User::removeCollabName(const MyString& collabName)
{
    for (int i = 0; i < collabNames.getSize(); i++)
    {
        if (collabNames[i] == collabName)
        {
            collabNames.erase(i);
            return;
        }
    }

    throw std::invalid_argument("There is no collab with this name");
}

void User::removeCollabPtr(unsigned collabTaskId)
{
    int collabTaskIndex = findCollabTaskIndexById(collabTaskId);
    if (collabTaskIndex == -1)
        throw std::invalid_argument("There is no such collabTask");

    collabTasks.erase(collabTaskIndex);

    if (isCollabTaskInDashBoard(collabTasks[collabTaskIndex]->getId()))
        dashboard.removeTaskId(collabTasks[collabTaskIndex]->getId());
}

void User::addCollabTaskPtr(CollaborationTask* ptr, unsigned collabTaskId)
{
    collabTasks.pushBack(ptr);
    setTaskStatus(Status::ON_HOLD, collabTaskId);
}

const Vector<Task>& User::getTasks() const
{
	return tasks;
}

const Vector<MyString>& User::getCollabNames() const
{
    return collabNames;
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
    collabNames.saveToBinary(ofs);
}

void User::loadUserFromBinary(std::ifstream& ifs)
{

    username.loadFromBinary(ifs);

    password.loadFromBinary(ifs);

    dashboard.loadFromBinary(ifs);
    tasks.loadFromBinary(ifs);
    /*if (dashboard.getCurrentDate() != getToday())
    {
        dashboard.freeTaskIds();
        for (int i = 0; i < tasks.getSize(); i++)
        {
            std::cout << "neshto" << std::endl;
            if (tasks[i].isDueDateToday())
                dashboard.addTaskId(tasks[i].getId());
        }
    }*/
   // createDashBoard();
    
    collabNames.loadFromBinary(ifs);
}

User::User(MyString&& username, MyString&& password) : username(std::move(username)), password(std::move(password))
{
    createDashBoard();
}

User::User(const MyString& username, const MyString& password) : username(username), password(password)
{
    createDashBoard();
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

bool User::isCollabNameUnique(const MyString& collabName) const
{
    for (int i = 0; i < collabNames.getSize(); i++)
    {
        if (collabNames[i] == collabName)
            return false;
    }
    return true;
}

int User::findTaskIndexById(unsigned id) const
{
    int index = -1;
    for (int i = 0; i < tasks.getSize(); i++)
    {
        if (tasks[i].getId() == id)

        {
            index = i;
            return index;
        }
    }

    return index;
}

int User::findCollabTaskIndexById(unsigned id) const
{
    // приемаме, че id-тата са различни от тези, които не са в колаборации
    int index = -1;
    for (int i = 0; i < collabTasks.getSize(); i++)
    {
        if (collabTasks[i]->getId() == id)
        {
            index = i;
            return index;
        }
            
    }

    return index;
}

void User::createDashBoard()
{
    if (dashboard.getCurrentDate() != getToday())
    {
        for (int i = 0; i < dashboard.getTaskIds().getSize(); i++)
        {
            int taskIndex = findTaskIndexById(dashboard.getTaskIds()[i]);
            int collabTaskIndex = findCollabTaskIndexById(dashboard.getTaskIds()[i]);

            if (taskIndex != -1 && tasks[taskIndex].isDateExpired())
            {
                setTaskStatus(Status::OVERDUE, dashboard.getTaskIds()[i]);
            }
            else if (collabTaskIndex!=-1&&collabTasks[collabTaskIndex]->isDateExpired())
            {
                setTaskStatus(Status::OVERDUE, dashboard.getTaskIds()[i]);
            }
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
            // priemame che id-tata sa razlichni
        }
    }
}
