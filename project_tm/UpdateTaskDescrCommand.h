#pragma once
#include "Command.h"
class UpdateTaskDescrCommand : public Command
{
public:
	UpdateTaskDescrCommand(TaskManager& tm, unsigned id, MyString&& description);
	void execute() override;
private:
	unsigned taskId;
	MyString description;
};

