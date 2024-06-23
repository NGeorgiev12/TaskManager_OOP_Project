#pragma once
#include "Command.h"
class ExitCommand : public Command
{
public:
	ExitCommand(TaskManager& tm);
	void execute() override;
};

