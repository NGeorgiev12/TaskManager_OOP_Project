#include "ListTasksCommand.h"
#include "SimpleTaskPrinter.h"

ListTasksCommand::ListTasksCommand(TaskManager& tm) : Command(tm)
{
}

ListTasksCommand::ListTasksCommand(TaskManager& tm, Optional<Date>&& dueDate) : Command(tm)
{
	this->dueDate = std::move(dueDate);
}

ListTasksCommand::ListTasksCommand(TaskManager& tm, Optional<MyString>&& collabName) : Command(tm)
{
	this->collabName = std::move(collabName);
}

// to do - da se pogrizha i za kolaboraciite
void ListTasksCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	const User& user = taskManager.getUsers()[taskManager.getCurrentUserIndex()];
	if (dueDate.has_value())
	{
		bool isTaskForTheDate = false;
			
		for (int i = 0; i < user.getTasks().getSize(); i++)
		{
			if (user.getTasks()[i].getDueDate() == dueDate.value())
			{
				SimpleTaskPrinter::getInstance().print(user.getTasks()[i]);
				isTaskForTheDate = true;
			}
		}

		for (int i = 0; i < user.getCollabTasksPtrs().getSize(); i++)
		{
			if (user.getCollabTasksPtrs()[i]->getDueDate() == dueDate.value())
			{
				SimpleTaskPrinter::getInstance().print(*user.getCollabTasksPtrs()[i]);
				isTaskForTheDate = true;
			}
		}

		if (!isTaskForTheDate)
		{
			std::cout << "There are no tasks for " << dueDate.value() << '!' << std::endl;
		}
	}
	else if (!collabName.has_value())
	{
		if (user.getTasks().getSize() == 0 && user.getCollabTasksPtrs().getSize() == 0)
		{
			std::cout << "User doesn't have any tasks!" << std::endl;
			return;
		}
		
		for (int i = 0; i < user.getTasks().getSize(); i++)
		{
			SimpleTaskPrinter::getInstance().print(user.getTasks()[i]);
		}

		for (int i = 0; i < user.getCollabTasksPtrs().getSize(); i++)
		{
			SimpleTaskPrinter::getInstance().print(*user.getCollabTasksPtrs()[i]);
		}
	}
	else if (collabName.has_value())
	{

		if (user.getCollabTasksPtrs().getSize() == 0)
		{
			std::cout << "User doesn't have any tasks in the collaboration!" << std::endl;
			return;
		}

		for (int i = 0; i < user.getCollabTasksPtrs().getSize(); i++)
		{
			SimpleTaskPrinter::getInstance().print(*user.getCollabTasksPtrs()[i]);
		}
	}
}
