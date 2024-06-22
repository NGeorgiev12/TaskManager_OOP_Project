#include "CollaborationTask.h"


const MyString& CollaborationTask::getAssignee() const
{
    return assignee;
}

void CollaborationTask::setAssignee(MyString&& newAssignee)
{
    assignee = std::move(newAssignee);
}

void CollaborationTask::saveToBinary(std::ofstream& ofs) const
{
    Task::saveToBinary(ofs);
    assignee.saveToBinary(ofs);
}

void CollaborationTask::loadFromBinary(std::ifstream& ifs)
{
    Task::loadFromBinary(ifs);
    assignee.loadFromBinary(ifs);
}
