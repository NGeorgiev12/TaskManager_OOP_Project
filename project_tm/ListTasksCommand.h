#pragma once
#include "Command.h"
class ListTasksCommand : public Command
{
public:
	ListTasksCommand(TaskManager& tm);
	ListTasksCommand(TaskManager& tm, Optional<Date>&& dueDate);
	void execute() override;
private:
	Optional<Date> dueDate;
	MyString collabName;
};

