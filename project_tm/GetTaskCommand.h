#pragma once
#include "Command.h"
class GetTaskCommand : public Command
{
public:
	GetTaskCommand(TaskManager& tm, unsigned taskId);
	GetTaskCommand(TaskManager& tm, MyString&& name);
	void execute() override;
private:
	unsigned taskId = 0;
	MyString name;
};

