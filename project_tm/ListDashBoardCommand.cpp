#include "ListDashBoardCommand.h"
#include "SimpleTaskPrinter.h"

ListDashBoardCommand::ListDashBoardCommand(TaskManager& tm) : Command(tm)
{
}

void ListDashBoardCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();
	
	const User& user = taskManager.getUsers()[userIndex];

	for (int i = 0; i < user.getTasks().getSize(); i++)
	{
		if (taskManager.isTaskInUserDashBoard(userIndex, user.getTasks()[i].getId()))
			SimpleTaskPrinter::getInstance().print(user.getTasks()[i]);
	}

	for (int i = 0; i < user.getCollabTasksPtrs().getSize(); i++)
	{
		if (taskManager.isTaskInUserDashBoard(userIndex, user.getCollabTasksPtrs()[i]->getId()))
			SimpleTaskPrinter::getInstance().print(*user.getCollabTasksPtrs()[i]);
	}
}
