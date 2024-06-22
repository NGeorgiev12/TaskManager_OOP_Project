#pragma once
#include "Command.h"
class UpdateTaskNameCommand : public Command
{
public:
	UpdateTaskNameCommand(TaskManager& taskMan, unsigned id, MyString&& name);
	void setId(unsigned id);
	void setName(MyString&& name);
	void execute() override;
	unsigned getId() const;
	const MyString& getName() const;
private:
	unsigned id = 0;
	MyString name;
};

