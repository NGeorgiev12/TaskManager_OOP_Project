#pragma once
#include "Command.h"
class AssignTaskCommand : public Command
{
public:
	AssignTaskCommand(TaskManager& taskMan, MyString&& collaborationName, MyString&& username, MyString&& name,
					  Date&& dueDate, MyString&& description);

	void execute() override;

private:
	MyString collaborationName;
	MyString username;
	MyString name; // taskName
	Date dueDate;
	MyString description;
};

