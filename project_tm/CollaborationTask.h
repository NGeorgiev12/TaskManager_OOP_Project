#pragma once
#include "Task.h"
#include <fstream>

class CollaborationTask : public Task
{
public:
	const MyString& getAssignee() const;
	void setAssignee(MyString&& newAssignee);

	void saveToBinary(std::ofstream& ofs) const;
	void loadFromBinary(std::ifstream& ifs);
private:
	MyString assignee;
};

