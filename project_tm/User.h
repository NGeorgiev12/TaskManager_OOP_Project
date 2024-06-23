#pragma once
#include "MyString.h"
#include "Task.h"
#include "DashBoard.h"
#include <fstream>
#include "CollaborationTask.h"

class User
{
public:
	const MyString& getUsername() const;
	const MyString& getPassword() const;
	const DashBoard& getDashBoard() const;
	const Vector<Task>& getTasks() const;
	const Vector<MyString>& getCollabNames() const;
	const Vector<CollaborationTask*>& getCollabTasksPtrs() const;

	void setUsername(const MyString& newUsername);
	void setPassword(const MyString& newPassword);
	void addCollaborationTask(CollaborationTask* task);

	User() = default;

	void addTask(Task&& task);
	void updateTaskName(unsigned id, MyString&& newName);
	void updateTaskDescription(unsigned id, MyString&& newDescription);
	void addTaskToDashBoard(unsigned id);
	bool isTaskInDashBoard(unsigned id) const;
	bool isCollabTaskInDashBoard(unsigned id) const;
	void removeTaskFromDashBoard(unsigned id);
	void deleteTask(unsigned taskId);
	void setTaskStatus(Status status, unsigned taskId);
	void addCollabName(const MyString& collabName);
	void removeCollabName(const MyString& collabName);
	void addCollabTaskPtr(CollaborationTask* ptr);
	/*void getTask(const MyString& name);
	void getTask(int id);
	void listTasks(const Date& date);
	void listTasks();
	void listCompletedTasks();
	void listDashboard();*/
	//void finishTask(int id);
	/*void registerUser(const MyString& username, const MyString& password);
	void loginUser(const MyString& username, const MyString& password);*/
	//Task& getTaskById(unsigned id);
	void saveUserInBinary(std::ofstream& ofs) const;
	void loadUserFromBinary(std::ifstream& ifs);

	User(const MyString& username, const MyString& password, const DashBoard& dashboard,
		const Vector<Task>& tasks, const Vector<MyString> collabTaskNames);
	User(MyString&& username, MyString&& password);

private:
	MyString username;
	MyString password;
	DashBoard dashboard;
	Vector<Task> tasks;
	Vector<MyString> collabNames;

	Vector<CollaborationTask*> collabTasks;
	//указателите сочат към вече заделена памет => не се нуждаем от голяма 6ца
	// class Collaboration е отговорен за тази памет
	/*
	void printTask(const Task& task) const;
	void regulateId();*/
	//void modifyDashboard();
	bool isIdUnique(unsigned id) const;
	bool isCollabIdUnique(unsigned id) const;
	int findTaskIndexById(unsigned id) const;
	int findCollabTaskIndexById(unsigned id) const;
	void createDashBoard();
	
};

