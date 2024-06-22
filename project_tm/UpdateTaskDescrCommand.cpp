#include "UpdateTaskDescrCommand.h"

UpdateTaskDescrCommand::UpdateTaskDescrCommand(TaskManager& tm, unsigned id, MyString&& description) : Command(tm)
{
	taskId = id;
	this->description = std::move(description);
}

void UpdateTaskDescrCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();
	taskManager.updateTaskDescrOfUser(userIndex, taskId, std::move(description));
	std::cout << "Task description updated successfully!" << std::endl;
}
