#include "UpdateTaskNameCommand.h"

UpdateTaskNameCommand::UpdateTaskNameCommand(TaskManager& taskMan, unsigned id, MyString&& name) : Command(taskMan)
{
	this->id = id;
	this->name = std::move(name);
}

void UpdateTaskNameCommand::execute()
{
	if(taskManager.getCurrentUserId() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserId();
	taskManager.updateTaskNameOfUser(userIndex, id, std::move(name));
}

