#pragma once
#include "Command.h"
class AddCollaborationCommand : public Command
{
public:
	AddCollaborationCommand(TaskManager& tm, MyString&& name);
	void execute() override;
private:
	MyString name;
};

