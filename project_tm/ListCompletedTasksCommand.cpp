#include "ListCompletedTasksCommand.h"
#include "SimpleTaskPrinter.h"

ListCompletedTasksCommand::ListCompletedTasksCommand(TaskManager& tm) : Command(tm)
{
}

void ListCompletedTasksCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();
	const User& user = taskManager.getUsers()[userIndex];
	bool isFinished = false;
	
	for (int i = 0; i < user.getTasks().getSize(); i++)
	{
		if (user.getTasks()[i].getStatus() == Status::DONE)
		{
			isFinished = true;
			SimpleTaskPrinter::getInstance().print(user.getTasks()[i]);
		}	
	}

	for (int i = 0; i < user.getCollabTasksPtrs().getSize(); i++)
	{
		if (user.getCollabTasksPtrs()[i]->getStatus() == Status::DONE)
		{
			isFinished = true;
			SimpleTaskPrinter::getInstance().print(*user.getCollabTasksPtrs()[i]);
		}
	}

	if (!isFinished)
		std::cout << "There is no finished tasks!" << std::endl;
}
