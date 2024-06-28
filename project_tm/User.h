#pragma once
#include "MyString.h"
#include "Task.h"
#include "DashBoard.h"
#include <fstream>
#include "CollaborationTask.h"

class User
{
public:
	// getters
	const MyString& getUsername() const;
	const MyString& getPassword() const;
	const DashBoard& getDashBoard() const;
	const Vector<Task>& getTasks() const;
	const Vector<MyString>& getCollabNames() const;
	const Vector<CollaborationTask*>& getCollabTasksPtrs() const;

	// setters
	void setUsername(const MyString& newUsername);
	void setPassword(const MyString& newPassword);

	// constructors
	User() = default;
	User(MyString&& username, MyString&& password);
	User(const MyString& username, const MyString& password);

	// add functions
	void addCollaborationTask(CollaborationTask* task);
	void addTask(Task&& task);
	void addTaskToDashBoard(unsigned id);
	void addCollabName(const MyString& collabName);
	void addCollabTaskPtr(CollaborationTask* ptr, unsigned collabTaskId);

	// remove functions
	void deleteTask(unsigned taskId);
	void removeCollabName(const MyString& collabName);
	void removeCollabPtr(unsigned collabTaskId);
	void removeTaskFromDashBoard(unsigned id);

	// modify functions
	void updateTaskName(unsigned id, MyString&& newName);
	void updateTaskDescription(unsigned id, MyString&& newDescription);
	void setTaskStatus(Status status, unsigned taskId);

	// const functions
	bool isTaskInDashBoard(unsigned id) const;
	bool isCollabTaskInDashBoard(unsigned id) const;
	
	// file reader and writer
	void saveUserInBinary(std::ofstream& ofs) const;
	void loadUserFromBinary(std::ifstream& ifs);
	
	void createDashBoard();


private:
	MyString username;
	MyString password;
	DashBoard dashboard;
	Vector<Task> tasks;
	Vector<MyString> collabNames;

	Vector<CollaborationTask*> collabTasks;
	//указателите сочат към вече заделена памет => не се нуждаем от голяма 6ца
	// class Collaboration е отговорен за тази памет
	
	bool isIdUnique(unsigned id) const;
	bool isCollabIdUnique(unsigned id) const;
	bool isCollabNameUnique(const MyString& collabName) const;
	int findTaskIndexById(unsigned id) const;
	int findCollabTaskIndexById(unsigned id) const;
	
	
};

