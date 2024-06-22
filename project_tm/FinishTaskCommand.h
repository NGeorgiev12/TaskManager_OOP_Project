#pragma once
#include "Command.h"
class FinishTaskCommand : public Command
{
public:
	FinishTaskCommand(TaskManager& tm, unsigned taskId);
	void execute() override;

public:
	unsigned taskId;
};

