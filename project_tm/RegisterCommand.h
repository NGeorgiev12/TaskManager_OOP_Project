#pragma once
#include "Command.h"
class RegisterCommand : public Command
{
public:
	RegisterCommand(TaskManager& taskManager, MyString&& username, MyString&& password);
	void execute() override;
private:
	MyString username;
	MyString password;
};

