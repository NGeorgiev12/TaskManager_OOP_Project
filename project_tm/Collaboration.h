#pragma once
#include "Vector.hpp"
#include "Task.h"
#include "CollaborationTask.h"
#include "Optional.hpp"

class Collaboration
{
public:
	unsigned getId() const;
	const MyString& getName() const;
	const Vector<CollaborationTask>& getTasks() const;
	const User& getCreator() const;
	const Vector<User>& getWorkGroup() const;

private:
	Vector<User> workGroup;
	User creator;
	Vector<CollaborationTask> tasks;
	MyString name;
	unsigned id = 0;
};

