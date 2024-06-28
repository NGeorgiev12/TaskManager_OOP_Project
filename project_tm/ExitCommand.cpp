#include "ExitCommand.h"

ExitCommand::ExitCommand(TaskManager& tm) : Command(tm)
{
}

void ExitCommand::execute()
{
	std::ofstream ofs(taskManager.getFileName().c_str(), std::ios::binary | std::ios::out);
	taskManager.saveToBinary(ofs);
	std::cout << "Exited successfully!\n";
}
