#pragma once
#include "Command.h"
class StartTaskCommand : public Command
{
public:
	StartTaskCommand(TaskManager& taskMan, unsigned taskId);
	void execute() override;

private:
	unsigned taskId;
};

