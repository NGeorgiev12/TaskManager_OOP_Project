#include "SimpleTaskPrinter.h"

SimpleTaskPrinter& SimpleTaskPrinter::getInstance()
{
	static SimpleTaskPrinter obj;
	return obj;
}

void SimpleTaskPrinter::print(const Task& task) const
{
	std::cout << "Task name : " << task.getTaskName() << std::endl;
	std::cout << "Task ID : " << task.getId() << std::endl;
	std::cout << "Due Date : " << task.getDueDate() << std::endl;
	std::cout << "Task description : " << task.getDescription() << std::endl;

	Status status = task.getStatus();
	static MyString prefix("Status: ");
	switch (status)
	{
	case Status::ON_HOLD:
		std::cout << prefix + "ON_HOLD" << std::endl;
		break;
	case Status::IN_PROCESS:
		std::cout << prefix + "IN_PROCESS" << std::endl;
		break;
	case Status::DONE:
		std::cout << prefix + "DONE" << std::endl;
		break;
	case Status::OVERDUE:
		std::cout << prefix + "OVERDUE" << std::endl;
		break;
	default:
		std::cout << prefix + "UNKNOWN" << std::endl;
		break;

	}
}
