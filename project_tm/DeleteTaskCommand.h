#pragma once
#include "Command.h"
class DeleteTaskCommand : public Command
{
public:
	DeleteTaskCommand(TaskManager& tm, unsigned taskId);
	void execute() override;
private:
	unsigned taskId;
};

