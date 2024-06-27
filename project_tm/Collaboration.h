#pragma once
#include "CollaborationTask.h"
#include "Vector.hpp"
#include <fstream>

class Collaboration
{
public:
	// getters
	unsigned getId() const;
	const MyString& getName() const;
	const Vector<CollaborationTask>& getTasks() const;
	const CollaborationTask* getCollTaskPtr(unsigned index) const;
	CollaborationTask* getCollTaskPtr(unsigned index);
	const MyString& getCreator() const;
	const Vector<MyString>& getWorkGroup() const;

	// constructors
	Collaboration() = default;
	Collaboration(unsigned id, const MyString& creator, MyString&& collabName);

	void addUserToWorkGroup(const MyString& username);
	void addUserToWorkGroup(MyString&& username);
	void addTask(const CollaborationTask& task);
	void addTask(CollaborationTask&& task);
	int findCollabTaskIndexById(unsigned id) const;
	
	// file reader and writer
	void saveToBinary(std::ofstream& ofs) const;
	void loadFromBinary(std::ifstream& ifs);
private:
	Vector<MyString> workGroup;
	MyString creator;
	Vector<CollaborationTask> tasks;
	MyString name;
	unsigned id = 0;
};

