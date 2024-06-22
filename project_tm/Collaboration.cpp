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

const User& Collaboration::getCreator() const
{
    return creator;
}

const Vector<User>& Collaboration::getWorkGroup() const
{
    return workGroup;
}
