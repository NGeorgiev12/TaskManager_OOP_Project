#include "AssignTaskCommand.h"

constexpr unsigned INITIAL_ID = 1;
static unsigned generateNextCollabTaskId(const User& user)
{
	if (user.getTasks().empty() && user.getCollabTasksPtrs().empty())
	{
		return INITIAL_ID;
	}

	unsigned lastTaskId = user.getTasks()[user.getTasks().getSize() - 1].getId();

	unsigned lastCollabTaskId;
	if (user.getCollabTasksPtrs().empty())
		lastCollabTaskId = 0;
	else
	{
		unsigned lastCollabTaskIndex = user.getCollabTasksPtrs().getSize() - 1;
		lastCollabTaskId = user.getCollabTasksPtrs()[lastCollabTaskIndex]->getId();
	}

	unsigned lastId = lastTaskId > lastCollabTaskId ? lastTaskId : lastCollabTaskId;
	return lastId + 1;
}
AssignTaskCommand::AssignTaskCommand(TaskManager& taskMan, MyString&& collaborationName, MyString&& username, MyString&& name, Date&& dueDate, MyString&& description) : Command(taskMan)
{
	this->collaborationName = std::move(collaborationName);
	this->username = std::move(username);
	this->dueDate = std::move(dueDate);
	this->description = std::move(description);
}

void AssignTaskCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int collabIndex = taskManager.findCollabIndexByName(collaborationName);
	int userIndex = taskManager.getCurrentUserIndex();
	const User& user = taskManager.getUsers()[userIndex];
	if (taskManager.isUserInCollaboration(username, taskManager.getCollabs()[collabIndex]))
	{
		unsigned id = generateNextCollabTaskId(user);
		taskManager.addCollabTask(CollaborationTask(id, std::move(name), std::move(dueDate), std::move(description), std::move(username)), collaborationName);
		CollaborationTask* ptr = taskManager.getCollabTaskPtr(collabIndex, id);
		taskManager.addCollabPtrToUser(userIndex, ptr);
	}
	else
	{
		throw std::invalid_argument("User is not in the collaboration!");
	}
}
