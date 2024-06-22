#pragma once
#include "Command.h"
class AddTaskToDashBoardCommand : public Command
{
public:
	AddTaskToDashBoardCommand(TaskManager& tm, unsigned id);
	void execute() override;
private:
	unsigned id;
};

