#include "AddTaskCommand.h"

constexpr unsigned INITIAL_ID = 1;
static unsigned generateNextId(const User& user)
{
	if (user.getTasks().empty())
	{
		return INITIAL_ID;
	}

	unsigned lastId = user.getTasks()[user.getTasks().getSize() - 1].getId();
	return lastId + 1;
}

AddTaskCommand::AddTaskCommand(TaskManager& tm, MyString&& name, Date&& dueDate, MyString&& description) : Command(tm)
{
	this->name = std::move(name);
	this->dueDate = std::move(dueDate);
	this->description = std::move(description);
}

void AddTaskCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	const User& user = taskManager.getUsers()[taskManager.getCurrentUserIndex()];

	for (int i = 0; i < user.getTasks().getSize(); i++)
	{
		if ((user.getTasks()[i].getTaskName() == name) && (user.getTasks()[i].getDueDate() == dueDate))
			throw std::invalid_argument("Task already exists!");
	}

	unsigned id = generateNextId(user);
	taskManager.addUserTask(Task(id, std::move(name), Optional<Date>(dueDate), std::move(description), std::move(Status::ON_HOLD)), taskManager.getCurrentUserIndex());
	
	std::cout << "Task added successfully!" << std::endl;
}
