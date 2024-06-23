#pragma once
#include "CollaborationTask.h"
#include "Vector.hpp"
#include <fstream>

class Collaboration
{
public:
	unsigned getId() const;
	const MyString& getName() const;
	const Vector<CollaborationTask>& getTasks() const;
	
	CollaborationTask* getCollTaskPtr(unsigned index);

	const MyString& getCreator() const;
	const Vector<MyString>& getWorkGroup() const;

	void addUserToWorkGroup(const MyString& username);
	void addUserToWorkGroup(MyString&& username);
	void addTask(const CollaborationTask& task);
	void addTask(CollaborationTask&& task);
	void saveToBinary(std::ofstream& ofs) const;
	void loadFromBinary(std::ifstream& ifs);
	int findCollabTaskIndexById(unsigned id) const;
	Collaboration() = default;
	Collaboration(unsigned id, const MyString& creator, MyString&& collabName);
private:
	Vector<MyString> workGroup;
	MyString creator;
	Vector<CollaborationTask> tasks;
	MyString name;
	unsigned id = 0;
};

