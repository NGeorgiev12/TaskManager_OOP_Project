#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "User.h"
#include <fstream>
#include "Task.h"
#include "Collaboration.h"

class TaskManager
{
public:
	TaskManager() = default;
	TaskManager(int currentUserIndex,
			    const Vector<User>& users, const Vector<Collaboration>& collabs);

	TaskManager(const char* fileName);
	const MyString& getName() const;
	const Vector<User>& getUsers() const;
	const Vector<Collaboration>& getCollabs() const;
	int getCurrentUserIndex() const;

	void setCurrentUserId(int newId);
	void addUserTask(Task&& task, int index);
	void updateTaskNameOfUser(int userIndex, unsigned taskId, MyString&& newName);
	void startTaskOfUser(int userIndex, unsigned taskId);
	void updateTaskDescrOfUser(int userIndex, unsigned taskId, MyString&& newDesc);
	void addTaskToUserDashBoard(int userIndex, unsigned taskId);
	bool isTaskInUserDashBoard(int userIndex, unsigned taskId) const;
	void removeTaskFromUserDashBoard(int userIndex, unsigned taskId);
	void deleteUserTask(int userIndex, unsigned taskId);
	void finishUserTask(int userIndex, unsigned taskId);
	void addCollaboration(Collaboration&& collab);
	void addCollabForUser(int userIndex, const MyString& collabName);
	void removeCollaboration(const MyString& collabName);
	void removeCollabNameForUser(int userIndex, const MyString& collabName);
	void addUserToCollabWorkGroup(const MyString& collabName, MyString&& username);
	TaskManager(const MyString& name);
	TaskManager(MyString&& name);
	int findCollabIndexByName(const MyString& collabName) const;
	void addUser(User&& user);
	bool isUserInCollaboration(const MyString& username, const Collaboration& collab) const;
	void addCollabTask(CollaborationTask&& task, const MyString& collabName);
	void addCollabPtrToUser(int userIndex, CollaborationTask* ptr);
	CollaborationTask* getCollabTaskPtr(int collabIndex, unsigned taskId);
	void setUserCollabTaskPtr(int userIndex, CollaborationTask* ptr);
	void saveToBinary(std::ofstream& ofs) const;
	void loadFromBinary(std::ifstream& ifs);
private:
	int currentUserIndex = -1;
	const MyString& name = "TaskManager"; // name of taskManager
	Vector<User> users;
	Vector<Collaboration> collabs;

};

