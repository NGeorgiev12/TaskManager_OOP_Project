#include "AddUserToCollaborationCommand.h"

AddUserToCollaborationCommand::AddUserToCollaborationCommand(TaskManager& taskManager, MyString&& collaborationName, MyString&& username) : Command(taskManager)
{
	this->collaborationName = std::move(collaborationName);
	this->username = std::move(username);
}

void AddUserToCollaborationCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	taskManager.addUserToCollabWorkGroup(collaborationName, std::move(username));
}
