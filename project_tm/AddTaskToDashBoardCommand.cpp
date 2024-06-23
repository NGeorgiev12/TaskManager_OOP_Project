#include "AddTaskToDashBoardCommand.h"

AddTaskToDashBoardCommand::AddTaskToDashBoardCommand(TaskManager& tm, unsigned id) : Command(tm)
{
	this->id = id;
}

void AddTaskToDashBoardCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();

	const User& user = taskManager.getUsers()[userIndex];

	for (int i = 0; i < user.getTasks().getSize(); i++)
	{
		if (user.getTasks()[i].getStatus() == Status::OVERDUE)
			throw std::invalid_argument("Task is with overdue status!");

		if (user.getTasks()[i].getId() == id)
		{
			taskManager.addTaskToUserDashBoard(userIndex, id);
			std::cout << "Task added successfully to the dashboard!" << std::endl;
			return;
		}
			
	}

	for (int i = 0; i < user.getCollabTasksPtrs().getSize(); i++)
	{
		if (user.getCollabTasksPtrs()[i]->getStatus() == Status::OVERDUE)
			throw std::invalid_argument("Task is with overdue status");

		if (user.getCollabTasksPtrs()[i]->getId() == id)
		{
			taskManager.addTaskToUserDashBoard(userIndex, id);
			std::cout << "Task added successfully to the dashboard!" << std::endl;
			return;
		}
	}
	throw std::invalid_argument("There is no task with this id");

}
