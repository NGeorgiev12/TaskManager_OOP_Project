#include "CollaborationTask.h"


const MyString& CollaborationTask::getAssignee() const
{
    return assignee;
}

void CollaborationTask::setAssignee(MyString&& newAssignee)
{
    assignee = std::move(newAssignee);
}
