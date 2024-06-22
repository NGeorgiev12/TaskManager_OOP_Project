#include "ListTasksCommand.h"
#include "SimpleTaskPrinter.h"

ListTasksCommand::ListTasksCommand(TaskManager& tm) : Command(tm)
{
}

ListTasksCommand::ListTasksCommand(TaskManager& tm, Optional<Date>&& dueDate) : Command(tm)
{
	this->dueDate = std::move(dueDate);
}

void ListTasksCommand::execute()
{
	if (taskManager.getCurrentUserId() == -1)
		throw std::invalid_argument("You need to login first!");

	const User& user = taskManager.getUsers()[taskManager.getCurrentUserId()];
	if (dueDate.has_value())
	{
		for (int i = 0; i < user.getTasks().getSize(); i++)
		{
			if (user.getTasks()[i].getDueDate() == dueDate.value())
			{
				SimpleTaskPrinter::getInstance().print(user.getTasks()[i]);
			}
		}
	}
	else
	{
		for (int i = 0; i < user.getTasks().getSize(); i++)
		{
			SimpleTaskPrinter::getInstance().print(user.getTasks()[i]);
		}
	}
}
