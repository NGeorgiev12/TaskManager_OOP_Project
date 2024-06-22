#pragma once
#include "Command.h"
class UpdateTaskNameCommand : public Command
{
public:
	UpdateTaskNameCommand(TaskManager& taskMan, unsigned id, MyString&& name);
	void execute() override;
private:
	unsigned id = 0;
	MyString name;
};

