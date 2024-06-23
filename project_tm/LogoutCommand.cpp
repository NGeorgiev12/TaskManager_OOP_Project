#include "LogoutCommand.h"

LogoutCommand::LogoutCommand(TaskManager& taskMan) : Command(taskMan)
{
}

void LogoutCommand::execute()
{
	taskManager.setCurrentUserId(-1);
	std::cout << "Logged out successfully!\n";

}
