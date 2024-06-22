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

Collaboration::Collaboration(const Vector<MyString>& workGroup, const MyString& creator, const Vector<CollaborationTask>& tasks, const MyString& name, unsigned id)
{
    this->workGroup = workGroup;
    this->creator = creator;
    this->tasks = tasks;
    this->name = name;
    this->id = id;
}
