#pragma once
#include "Command.h"
class RemoveTaskFromDashBoardCommand : public Command
{
public:
	RemoveTaskFromDashBoardCommand(TaskManager& tm, unsigned taskId);
	void execute() override;
private:
	unsigned taskId;
};

