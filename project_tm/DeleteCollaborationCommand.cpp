#include "DeleteCollaborationCommand.h"

static void deleteUserCollabPtrs(TaskManager& tm, const User& user, const Collaboration& collab, int userIndex)
{
	for (int i = 0; i < collab.getTasks().getSize(); i++)
	{
		if (user.getCollabTasksPtrs()[i]->getId() == collab.getTasks()[i].getId())
			tm.removeUserCollabPtr(userIndex, collab.getTasks()[i].getId());
	}
}

DeleteCollaborationCommand::DeleteCollaborationCommand(TaskManager& taskManager, MyString&& collabName) : Command(taskManager)
{
	this->collabName = std::move(collabName);
}

void DeleteCollaborationCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();
	int collabIndex = taskManager.findCollabIndexByName(collabName);
	if (collabIndex == -1)
		throw std::invalid_argument("There is no such collaboration!");

	MyString creator = taskManager.getCollabs()[collabIndex].getCreator();
	const Collaboration& collab = taskManager.getCollabs()[collabIndex];
	if (taskManager.getUsers()[userIndex].getUsername() == creator)
	{
		taskManager.removeCollabNameForUser(userIndex, collabName);
		for (int i = 0; i < taskManager.getUsers().getSize(); i++)
		{
			const User& currentUser = taskManager.getUsers()[i];
			int currentUserIndex = taskManager.findUserIndexByUsername(currentUser.getUsername());
			if (taskManager.isUserInCollaboration(currentUser.getUsername(), collab))
			{
				
				deleteUserCollabPtrs(taskManager, currentUser, collab, currentUserIndex);
			}
		}
		taskManager.removeCollaboration(collabName);
		std::cout << "Collaboration deleted successfully!" << std::endl;
	}
	else
	{
		throw std::invalid_argument("You are not the creator of the collaboration!");
	}
}
