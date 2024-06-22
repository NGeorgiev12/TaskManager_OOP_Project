#pragma once
#include "Command.h"
class ListDashBoardCommand : public Command
{
public:

	ListDashBoardCommand(TaskManager& tm);
	void execute() override;
private:

};

