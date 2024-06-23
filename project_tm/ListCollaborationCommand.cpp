#include "ListCollaborationCommand.h"

ListCollaborationCommand::ListCollaborationCommand(TaskManager& taskMan) : Command(taskMan)
{
}

void ListCollaborationCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();
	const User& user = taskManager.getUsers()[userIndex];

	for (int i = 0; i < user.getCollabNames().getSize(); i++)
	{
		std::cout << user.getCollabNames()[i] << std::endl;
	}
}
