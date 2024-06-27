#include "Collaboration.h"

unsigned Collaboration::getId() const
{
    return id;
}

const MyString& Collaboration::getName() const
{
    return name;
}

const Vector<CollaborationTask>& Collaboration::getTasks() const
{
    return tasks;
}

const CollaborationTask* Collaboration::getCollTaskPtr(unsigned index) const
{
    return &tasks[index];
}

CollaborationTask* Collaboration::getCollTaskPtr(unsigned index)
{
    return &tasks[index];
}

const MyString& Collaboration::getCreator() const
{
    return creator;
}

const Vector<MyString>& Collaboration::getWorkGroup() const
{
    return workGroup;
}

void Collaboration::addUserToWorkGroup(const MyString& username)
{
    workGroup.pushBack(username);
}

void Collaboration::addUserToWorkGroup(MyString&& username)
{
    workGroup.pushBack(std::move(username));
}

void Collaboration::addTask(const CollaborationTask& task)
{
    tasks.pushBack(task);
}

void Collaboration::addTask(CollaborationTask&& task)
{
    tasks.pushBack(std::move(task));
}

void Collaboration::saveToBinary(std::ofstream& ofs) const
{
    workGroup.saveToBinary(ofs);
    creator.saveToBinary(ofs);
    tasks.saveToBinary(ofs);
    name.saveToBinary(ofs);
    ofs.write(reinterpret_cast<const char*>(&id), sizeof(unsigned));
}

void Collaboration::loadFromBinary(std::ifstream& ifs)
{
    workGroup.loadFromBinary(ifs);
    creator.loadFromBinary(ifs);
    tasks.loadFromBinary(ifs);
    name.loadFromBinary(ifs);
    ifs.read(reinterpret_cast<char*>(&id), sizeof(unsigned));
}

int Collaboration::findCollabTaskIndexById(unsigned id) const
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

Collaboration::Collaboration(unsigned id, const MyString& creator, MyString&& collabName)
{
    this->id = id;
    this->creator = creator;
    name = std::move(collabName);
}
