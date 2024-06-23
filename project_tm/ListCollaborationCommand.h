#pragma once
#include "Command.h"
class ListCollaborationCommand : public Command
{
public:
	ListCollaborationCommand(TaskManager& taskMan);
	void execute() override;
};

