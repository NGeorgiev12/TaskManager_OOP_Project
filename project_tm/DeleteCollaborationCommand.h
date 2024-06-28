#pragma once
#include "Command.h"
class DeleteCollaborationCommand : public Command
{
public:
	DeleteCollaborationCommand(TaskManager& taskManager, MyString&& collabName);
	void execute() override;
private:
	MyString collabName;
};

