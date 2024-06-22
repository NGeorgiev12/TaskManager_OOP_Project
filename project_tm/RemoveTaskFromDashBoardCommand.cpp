#include "RemoveTaskFromDashBoardCommand.h"

RemoveTaskFromDashBoardCommand::RemoveTaskFromDashBoardCommand(TaskManager& tm, unsigned taskId) : Command(tm)
{
	this->taskId = taskId;
}

void RemoveTaskFromDashBoardCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();
	taskManager.removeTaskFromUserDashBoard(userIndex, taskId);
	std::cout << "Task removed successfully from dashboard!" << std::endl;
}
