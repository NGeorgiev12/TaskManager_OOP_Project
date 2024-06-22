#pragma once
#include "Command.h"
class AddTaskCommand : public Command
{
public:
	AddTaskCommand(TaskManager& tm, MyString&& name, Date&& dueDate, MyString&& description);
	void execute() override;
private:
	MyString name;
	Date dueDate;
	MyString description;
};

