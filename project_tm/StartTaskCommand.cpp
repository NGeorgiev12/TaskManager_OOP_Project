#include "StartTaskCommand.h"

StartTaskCommand::StartTaskCommand(TaskManager& taskMan, unsigned taskId) : Command(taskMan)
{
	this->taskId = taskId;
}

void StartTaskCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	taskManager.startTaskOfUser(taskManager.getCurrentUserIndex(), taskId);
	std::cout << "Task started successfully!" << std::endl;
}
