#pragma once
#include "MyString.h"
#include "Task.h"
#include "DashBoard.h"
#include <fstream>
#include "Collaboration.h"

class User
{
public:
	const MyString& getUsername() const;
	const MyString& getPassword() const;

	void setUsername(const MyString& newUsername);
	void setPassword(const MyString& newPassword);

	User() = default;

	void addTask(Task&& task);
	/*void updateTask(int id, const MyString& newName);
	void startTask(int id);
	void updateTaskDescription(int id, const MyString& newDescription);*/

	const Vector<Task>& getTasks() const;
	/*void deleteTask(int id);
	void getTask(const MyString& name);
	void getTask(int id);
	void listTasks(const Date& date);
	void listTasks();
	void listCompletedTasks();
	void listDashboard();*/
	//void finishTask(int id);
	/*void registerUser(const MyString& username, const MyString& password);
	void loginUser(const MyString& username, const MyString& password);*/
	//Task& getTaskById(unsigned id);
//protected:
//	void saveUserInBinary(std::ofstream& ofs);
//	void loadUserFromBinary(std::ifstream& ifs);

private:
	MyString username;
	MyString password;
	DashBoard dashboard;
	Vector<Task> tasks;
	Vector<MyString> collabTaskNames;
	/*int findTaskIndexById(int id) const;
	void printTask(const Task& task) const;
	void regulateId();*/
	//void modifyDashboard();
	
};

