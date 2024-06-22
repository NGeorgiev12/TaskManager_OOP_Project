#pragma once
#include "Task.h"

class CollaborationTask : public Task
{
public:
	const MyString& getAssignee() const;
	void setAssignee(MyString&& newAssignee);
private:
	MyString assignee;
};

