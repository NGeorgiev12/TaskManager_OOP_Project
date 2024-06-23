#include "GetTaskCommand.h"
#include "SimpleTaskPrinter.h"

GetTaskCommand::GetTaskCommand(TaskManager& tm, unsigned taskId) : Command(tm)
{
	this->taskId = taskId;
}

GetTaskCommand::GetTaskCommand(TaskManager& tm, MyString&& name) : Command(tm)
{
	this->name = std::move(name);
}

void GetTaskCommand::execute()
{
	if (taskManager.getCurrentUserIndex() == -1)
		throw std::invalid_argument("You need to login first!");

	int userIndex = taskManager.getCurrentUserIndex();
	const User& user = taskManager.getUsers()[userIndex];

	if (taskId)
	{
		for (int i = 0; i < user.getTasks().getSize(); i++)
		{
			if (user.getTasks()[i].getId() == taskId)
			{
				SimpleTaskPrinter::getInstance().print(user.getTasks()[i]);
				return;
			}
		}

		for (int i = 0; i < user.getCollabTasksPtrs().getSize(); i++)
		{
			if (user.getCollabTasksPtrs()[i]->getId() == taskId)
			{
				SimpleTaskPrinter::getInstance().print(*user.getCollabTasksPtrs()[i]);
				return;
			}
		}

		throw std::invalid_argument("Incorrect taskId!");
	}
	else
	{
		int minTaskIndex = INT32_MAX;
		int minCollabTaskIndex = INT32_MAX;
		for (int i = 0; i < user.getTasks().getSize(); i++)
		{
			if (user.getTasks()[i].getTaskName() == name)
			{
				minTaskIndex = i;
				break;
				// id-tata sa podredeni vuzhodyashto => vinagi shte se vzema purviq
			}
		}

		for (int i = 0; i < user.getCollabTasksPtrs().getSize(); i++)
		{
			if (user.getCollabTasksPtrs()[i]->getTaskName() == name)
			{
				minCollabTaskIndex = i;
				break;
			}
		}

		bool isTaskSmallerThanCollab = minTaskIndex < minCollabTaskIndex;
		int minIndex = isTaskSmallerThanCollab ? minTaskIndex : minCollabTaskIndex;

		if (isTaskSmallerThanCollab && minIndex < INT32_MAX)
		{
			SimpleTaskPrinter::getInstance().print(user.getTasks()[minIndex]);
			return;
		}
		else if (!isTaskSmallerThanCollab && minIndex < INT32_MAX)
		{
			SimpleTaskPrinter::getInstance().print(*user.getCollabTasksPtrs()[minIndex]);
			return;
		}
		throw std::invalid_argument("Incorrect taskName!");
	}
	
}
