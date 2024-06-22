#pragma once
#include "MyString.h"
#include "Vector.hpp"
#include "User.h"
#include <fstream>
#include "Task.h"

class TaskManager
{
public:

	const MyString& getName() const;
	const Optional<User>& getUser() const;

	void setUserTask(Task&& task);
	TaskManager(const MyString& name);
	TaskManager(MyString&& name);

	void setUser(User&& user);
private:
	Optional<User> currentUser;
	MyString name; // name of taskManager
	Vector<MyString> usernames;


};

