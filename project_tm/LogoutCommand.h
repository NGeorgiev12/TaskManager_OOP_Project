#pragma once
#include "Command.h"
class LogoutCommand : public Command
{
public:
	LogoutCommand(TaskManager& taskMan);
	void execute() override;
};

