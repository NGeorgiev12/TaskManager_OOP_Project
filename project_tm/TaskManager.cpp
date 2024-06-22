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

TaskManager::TaskManager(int currentUserIndex, const MyString& name, const Vector<User>& users, const Vector<Collaboration>& collabs)
{
	this->currentUserIndex = currentUserIndex;
	this->users = users;
	this->name = name;
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
	users[userIndex].startTask(taskId);
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

//const Optional<User>& TaskManager::getUser() const
//{
//	return currentUser;
//}
//
//void TaskManager::setUserTask(Task&& task)
//{
//	(*currentUser).addTask(std::move(task));
//}

TaskManager::TaskManager(const MyString& name) : name(name)
{
}

TaskManager::TaskManager(MyString&& name) : name(std::move(name))
{
}

void TaskManager::addUser(User&& user)
{
	users.pushBack(std::move(user));
}

void TaskManager::saveToBinary(std::ofstream& ofs) const
{
	ofs.write(reinterpret_cast<const char*>(&currentUserIndex), sizeof(int));
	name.saveToBinary(ofs);

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
	name.loadFromBinary(ifs);

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

		// to do - da vzemem ukazateli ot kolaboraciqta
		SetUserCollabTasks(user, collabs);
		users.pushBack(std::move(user));

	}
}
