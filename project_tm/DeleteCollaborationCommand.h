#pragma once
#include "Command.h"
class DeleteCollaborationCommand : public Command
{
public:
	DeleteCollaborationCommand(TaskManager& taskManager, MyString&& name);
	void execute() override;
private:
	MyString name;
};

