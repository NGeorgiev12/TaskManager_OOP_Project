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
	TaskManager(int currentUserIndex, const MyString& name,
			    const Vector<User>& users, const Vector<Collaboration>& collabs);

	TaskManager(const char* fileName);
	const MyString& getName() const;
	const Vector<User>& getUsers() const;
	const Vector<Collaboration>& getCollabs() const;
	int getCurrentUserId() const;

	void setCurrentUserId(int newId);
	void addUserTask(Task&& task, int index);
	void updateTaskNameOfUser(int userIndex, unsigned taskId, MyString&& newName);
	void startTaskOfUser(int userIndex, unsigned taskId);
	void updateTaskDescrOfUser(int userIndex, unsigned taskId, MyString&& newDesc);
	TaskManager(const MyString& name);
	TaskManager(MyString&& name);

	void addUser(User&& user);

	void saveToBinary(std::ofstream& ofs) const;
	void loadFromBinary(std::ifstream& ifs);
private:
	int currentUserIndex = -1;
	MyString name; // name of taskManager
	Vector<User> users;
	Vector<Collaboration> collabs;


};

