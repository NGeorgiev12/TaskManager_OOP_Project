#include "TaskManager.h"

const MyString& TaskManager::getName() const
{
	return name;
}

const Optional<User>& TaskManager::getUser() const
{
	return currentUser;
}

void TaskManager::setUserTask(Task&& task)
{
	(*currentUser).addTask(std::move(task));
}

TaskManager::TaskManager(const MyString& name) : name(name)
{
}

TaskManager::TaskManager(MyString&& name) : name(std::move(name))
{
}

void TaskManager::setUser(User&& user)
{
	this->currentUser = std::move(user);
}
