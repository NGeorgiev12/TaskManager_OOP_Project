#pragma once
#include "Command.h"
class LoginCommand : public Command
{
public:
	LoginCommand(TaskManager& taskMan, MyString&& username, MyString&& password);

	void execute() override;

private:
	MyString username;
	MyString password;
};

