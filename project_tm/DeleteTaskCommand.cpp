#include "DeleteTaskCommand.h"

DeleteTaskCommand::DeleteTaskCommand(TaskManager& tm, unsigned taskId) : Command(tm)
{
	this->taskId = taskId;
}

void DeleteTaskCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();
	taskManager.deleteUserTask(userIndex, taskId);
	std::cout << "Task deleted successfully!" << std::endl;
}
