#pragma once
#include "Command.h"
class AddUserToCollaborationCommand : public Command
{
public:
	AddUserToCollaborationCommand(TaskManager& taskManager, MyString&& collaborationName, MyString&& username);
	void execute() override;
private:
	MyString collaborationName;
	MyString username;
};

