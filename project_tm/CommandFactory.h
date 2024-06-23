#pragma once
#include "Command.h"

class CommandFactory
{
public:
	static Command* makeCommand(TaskManager& tm, const MyString& str);
};

