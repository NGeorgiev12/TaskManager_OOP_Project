#include "UpdateTaskDescrCommand.h"

UpdateTaskDescrCommand::UpdateTaskDescrCommand(TaskManager& tm, unsigned id, MyString&& description) : Command(tm)
{
	taskId = id;
	this->description = std::move(description);
}

void UpdateTaskDescrCommand::execute()
{
	if (taskManager.getCurrentUserId() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserId();
	taskManager.updateTaskDescrOfUser(userIndex, taskId, std::move(description));
}
