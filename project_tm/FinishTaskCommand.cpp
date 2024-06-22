#include "FinishTaskCommand.h"

FinishTaskCommand::FinishTaskCommand(TaskManager& tm, unsigned taskId) : Command(tm)
{
	this->taskId = taskId;
}

void FinishTaskCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();

}
