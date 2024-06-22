#pragma once
#include "Command.h"
class ListCompletedTasksCommand : public Command
{
public:
	ListCompletedTasksCommand(TaskManager& tm);
	void execute() override;
};

