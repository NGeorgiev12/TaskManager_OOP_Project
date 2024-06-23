#include "ExitCommand.h"

ExitCommand::ExitCommand(TaskManager& tm) : Command(tm)
{
}

void ExitCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	MyString fileName = taskManager.getName() + ".dat";

	std::ofstream ofs(fileName.c_str(), std::ios::binary | std::ios::out);
	taskManager.saveToBinary(ofs);
	std::cout << "Exited successfully!\n";
}
