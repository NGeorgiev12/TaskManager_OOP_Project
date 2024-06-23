#pragma once
#include "CollaborationTask.h"
#include "User.h"
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

	void saveToBinary(std::ofstream& ofs) const;
	void loadFromBinary(std::ifstream& ifs);

	Collaboration(const Vector<MyString>& workGroup, const MyString& creator, const Vector<CollaborationTask>& tasks, const MyString& name, unsigned id);
	Collaboration() = default;
	Collaboration(unsigned id, const MyString& creator, MyString&& collabName);
private:
	Vector<MyString> workGroup;
	MyString creator;
	Vector<CollaborationTask> tasks;
	MyString name;
	unsigned id = 0;

};

