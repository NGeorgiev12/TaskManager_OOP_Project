#pragma once
#include "Command.h"
class ListTasksCommand : public Command
{
public:
	ListTasksCommand(TaskManager& tm);
	ListTasksCommand(TaskManager& tm, Optional<Date>&& dueDate);
	ListTasksCommand(TaskManager& tm, Optional<MyString>&& collabName);

	void execute() override;
private:
	Optional<Date> dueDate;
	Optional<MyString> collabName;
};

