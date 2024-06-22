#pragma once
#include "TaskManager.h"

class Command
{
public:
	virtual void execute() = 0;
	virtual ~Command() = default;
	Command(TaskManager& taskManager);

protected:
	TaskManager& taskManager;
};

