#include "SimpleTaskPrinter.h"

void SimpleTaskPrinter::print(const Task& task) const
{
	std::cout << "Task name : " << task.getTaskName() << std::endl;
	std::cout << "Task ID : " << task.getId() << std::endl;
	std::cout << "Due Date : " << task.getDueDate() << std::endl;
	std::cout << "Task name : " << task.getTaskName() << std::endl;
}
