#include "AddCollaborationCommand.h"

const unsigned INITIAL_ID = 1;
static unsigned generateNextCollabId(const TaskManager& taskManager)
{
	if (taskManager.getCollabs().empty())
	{
		return INITIAL_ID;
	}

	unsigned lastCollabId = taskManager.getCollabs()[taskManager.getCollabs().getSize() - 1].getId();
	return lastCollabId + 1;
}

AddCollaborationCommand::AddCollaborationCommand(TaskManager& tm, MyString&& name) : Command(tm)
{
	this->name = name;
}

void AddCollaborationCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	unsigned collabId = generateNextCollabId(taskManager);
	int userIndex = taskManager.getCurrentUserIndex();
	MyString username = taskManager.getUsers()[userIndex].getUsername();
	taskManager.addCollabForUser(userIndex, name);
	taskManager.addCollaboration(Collaboration(collabId, username, std::move(name)));
}
