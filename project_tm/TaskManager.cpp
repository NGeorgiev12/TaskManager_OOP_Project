#include "TaskManager.h"

static void SetUserCollabTasks(User& user, Vector<Collaboration>& collabs)
{
	for (int i = 0; i < collabs.getSize(); i++)
	{
		for (int j = 0; j < user.getCollabNames().getSize(); j++)
		{
			if (collabs[i].getName() == user.getCollabNames()[j])
			{
				for (int k = 0; k < collabs[i].getTasks().getSize(); k++)
				{
					if (collabs[i].getTasks()[k].getAssignee() == user.getUsername())
					{
						CollaborationTask* taskPtr = collabs[i].getCollTaskPtr(k);
						user.addCollaborationTask(taskPtr);
					}
				}
			}
		}
	}
}

TaskManager::TaskManager(int currentUserIndex, const Vector<User>& users, const Vector<Collaboration>& collabs)
{
	this->currentUserIndex = currentUserIndex;
	this->users = users;
	this->collabs = collabs;
}

TaskManager::TaskManager(const char* fileName)
{

	std::ifstream ifs(fileName, std::ios::binary | std::ios::in);

	if (!ifs.is_open())
	{
		throw std::runtime_error("Cannot open stream!");
	}
	
	loadFromBinary(ifs);
}

const MyString& TaskManager::getName() const
{
	return name;
}

const Vector<User>& TaskManager::getUsers() const
{
	return users;
}

const Vector<Collaboration>& TaskManager::getCollabs() const
{
	return collabs;
}

int TaskManager::getCurrentUserIndex() const
{
	return currentUserIndex;
}

void TaskManager::setCurrentUserId(int newId)
{
	currentUserIndex = newId;
}

void TaskManager::addUserTask(Task&& task, int index)
{
	users[index].addTask(std::move(task));
}

void TaskManager::updateTaskNameOfUser(int userIndex, unsigned taskIndex, MyString&& newName)
{
	users[userIndex].updateTaskName(taskIndex, std::move(newName));
}

void TaskManager::startTaskOfUser(int userIndex, unsigned taskId)
{
	users[userIndex].setTaskStatus(Status::IN_PROCESS, taskId);
}

void TaskManager::updateTaskDescrOfUser(int userIndex, unsigned taskId, MyString&& newDesc)
{
	users[userIndex].updateTaskDescription(taskId, std::move(newDesc));
}

void TaskManager::addTaskToUserDashBoard(int userIndex, unsigned taskId)
{
	users[userIndex].addTaskToDashBoard(taskId);
}

bool TaskManager::isTaskInUserDashBoard(int userIndex, unsigned taskId) const
{
	return users[userIndex].isTaskInDashBoard(taskId);
}

void TaskManager::removeTaskFromUserDashBoard(int userIndex, unsigned taskId)
{
	users[userIndex].removeTaskFromDashBoard(taskId);
}

void TaskManager::deleteUserTask(int userIndex, unsigned taskId)
{
	users[userIndex].deleteTask(taskId);
}

void TaskManager::finishUserTask(int userIndex, unsigned taskId)
{
	users[userIndex].setTaskStatus(Status::DONE, taskId);
}

void TaskManager::addCollaboration(Collaboration&& collab)
{
	collabs.pushBack(collab);
}

void TaskManager::addCollabForUser(int userIndex, const MyString& collabName)
{
	users[userIndex].addCollabName(collabName);
}

void TaskManager::removeCollaboration(const MyString& collabName)
{
	int collabIndex = findCollabIndexByName(collabName);

	if (collabIndex == -1)
		throw std::invalid_argument("Invalid collab name!");

	collabs.erase(collabIndex);
}

void TaskManager::removeCollabNameForUser(int userIndex, const MyString& collabName)
{
	users[userIndex].removeCollabName(collabName);
}

void TaskManager::addUserToCollabWorkGroup(const MyString& collabName, MyString&& username)
{	
	int collabIndex = findCollabIndexByName(collabName);
	if (!isUserInCollaboration(username, collabs[collabIndex]))
	{
		collabs[collabIndex].addUserToWorkGroup(std::move(username));

	}
	else
		throw std::invalid_argument("User is already in the collaboration!");
}

void TaskManager::addUser(User&& user)
{
	users.pushBack(std::move(user));
}

bool TaskManager::isUserInCollaboration(const MyString& username, const Collaboration& collab) const
{
	for (int i = 0; i < collab.getWorkGroup().getSize(); i++)
	{
		if (collab.getWorkGroup()[i] == username)
			return true;
	}
	return false;
}

void TaskManager::addCollabTask(CollaborationTask&& task, const MyString& collabName)
{
	int collabIndex = findCollabIndexByName(collabName);
	collabs[collabIndex].addTask(std::move(task));
}

void TaskManager::addCollabPtrToUser(int userIndex, CollaborationTask* ptr, unsigned collabTaskId)
{
	users[userIndex].addCollabTaskPtr(ptr, collabTaskId);
}

const CollaborationTask* TaskManager::getCollabTaskPtr(int collabIndex, unsigned taskId) const
{
	int taskIndex = collabs[collabIndex].findCollabTaskIndexById(taskId);
	return collabs[collabIndex].getCollTaskPtr(taskIndex);
}

CollaborationTask* TaskManager::getCollabTaskPtr(int collabIndex, unsigned taskId)
{
	int taskIndex = collabs[collabIndex].findCollabTaskIndexById(taskId);
	return collabs[collabIndex].getCollTaskPtr(taskIndex);
}

void TaskManager::saveToBinary(std::ofstream& ofs) const
{
	ofs.write(reinterpret_cast<const char*>(&currentUserIndex), sizeof(int));

	size_t collabsCount = collabs.getSize();
	ofs.write(reinterpret_cast<const char*>(&collabsCount), sizeof(size_t));
	for (int i = 0; i < collabsCount; i++)
	{
		collabs[i].saveToBinary(ofs);
	}

	size_t usersCount = users.getSize();
	ofs.write(reinterpret_cast<const char*>(&usersCount), sizeof(size_t));

	for (int i = 0; i < usersCount; i++)
	{
		users[i].saveUserInBinary(ofs);
	}
}

void TaskManager::loadFromBinary(std::ifstream& ifs)
{
	ifs.read(reinterpret_cast<char*>(&currentUserIndex), sizeof(int));

	size_t collabsCount = 0;
	ifs.read(reinterpret_cast<char*>(&collabsCount), sizeof(size_t));
	for (int i = 0; i < collabsCount; i++)
	{

		Collaboration collab;
		collab.loadFromBinary(ifs);
		collabs.pushBack(std::move(collab));
	}

	size_t usersCount = 0;
	ifs.read(reinterpret_cast<char*>(&usersCount), sizeof(size_t));

	for (int i = 0; i < usersCount; i++)
	{
		User user;

		user.loadUserFromBinary(ifs);

		SetUserCollabTasks(user, collabs);
		users.pushBack(std::move(user));
	}
}

int TaskManager::findCollabIndexByName(const MyString& collabName) const
{
	int index = -1;
	for (int i = 0; i < collabs.getSize(); i++)
	{
		if (collabs[i].getName() == collabName)
		{
			index = i;
			return index;
		}
	}
	return index;
}

int TaskManager::findUserIndexByUsername(const MyString& username) const
{
	int index = -1;
	for (int i = 0; i < users.getSize(); i++)
	{
		if (users[i].getUsername() == username)
		{
			index = i;
			return index;
		}
	}
	return index;
}
