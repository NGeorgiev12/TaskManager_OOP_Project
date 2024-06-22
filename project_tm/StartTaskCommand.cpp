#include "StartTaskCommand.h"

StartTaskCommand::StartTaskCommand(TaskManager& taskMan, unsigned taskId) : Command(taskMan)
{
	this->taskId = taskId;
}

void StartTaskCommand::execute()
{
	if (taskManager.getCurrentUserId() == -1)
		throw std::invalid_argument("You need to login first!");

	taskManager.startTaskOfUser(taskManager.getCurrentUserId(), taskId);
}
