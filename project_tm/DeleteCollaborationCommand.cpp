#include "DeleteCollaborationCommand.h"

DeleteCollaborationCommand::DeleteCollaborationCommand(TaskManager& taskManager, MyString&& name) : Command(taskManager)
{
	this->name = std::move(name);
}

void DeleteCollaborationCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();
	int collabIndex = taskManager.findCollabIndexByName(name);
	MyString creator = taskManager.getCollabs()[collabIndex].getCreator();
	if (taskManager.getUsers()[userIndex].getUsername() == creator)
	{
		// to do
	}
	else
	{
		throw std::invalid_argument("You are not the creator of the collaboration");
	}
}
