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
	// constructors
	TaskManager(const MyString& fileName);

	// getters
	const MyString& getFileName() const;
	const Vector<User>& getUsers() const;
	const Vector<Collaboration>& getCollabs() const;
	int getCurrentUserIndex() const;
	const CollaborationTask* getCollabTaskPtr(int collabIndex, unsigned taskId) const ; 
	CollaborationTask* getCollabTaskPtr(int collabIndex, unsigned taskId); // not const because user doesn't own the collabTask

	// add functions
	void addUserTask(Task&& task, int index);
	void addTaskToUserDashBoard(int userIndex, unsigned taskId);
	void addCollaboration(Collaboration&& collab);
	void addCollabForUser(int userIndex, const MyString& collabName);
	void addUserToCollabWorkGroup(const MyString& collabName, MyString&& username);
	void addCollabTask(CollaborationTask&& task, const MyString& collabName);
	void addCollabPtrToUser(int userIndex, CollaborationTask* ptr, unsigned collabTaskId);
	void addUser(User&& user);

	// remove functions
	void removeTaskFromUserDashBoard(int userIndex, unsigned taskId);
	void deleteUserTask(int userIndex, unsigned taskId);
	void removeCollaboration(const MyString& collabName);
	void removeCollabNameForUser(int userIndex, const MyString& collabName);
	void removeUserCollabPtr(int userIndex, unsigned collabTaskId);

	// modify functions
	void setCurrentUserId(int newId);
	void updateTaskNameOfUser(int userIndex, unsigned taskId, MyString&& newName);
	void startTaskOfUser(int userIndex, unsigned taskId);
	void updateTaskDescrOfUser(int userIndex, unsigned taskId, MyString&& newDesc);
	void finishUserTask(int userIndex, unsigned taskId);

	// const functions
	bool isTaskInUserDashBoard(int userIndex, unsigned taskId) const;
	int findCollabIndexByName(const MyString& collabName) const;
	int findUserIndexByUsername(const MyString& username) const;
	bool isUserInCollaboration(const MyString& username, const Collaboration& collab) const;
	
	// file reader and writer
	void saveToBinary(std::ofstream& ofs) const;
	void loadFromBinary(std::ifstream& ifs);

private:
	int currentUserIndex = -1;
	MyString fileName;
	Vector<User> users;
	Vector<Collaboration> collabs;

};

