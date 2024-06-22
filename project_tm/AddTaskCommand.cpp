#include "AddTaskCommand.h"

constexpr unsigned INITIAL_ID = 1;
static unsigned generateNextId(const Vector<Task>& tasks)
{
	if (tasks.empty())
	{
		return INITIAL_ID;
	}

	unsigned lastId = tasks[tasks.getSize() - 1].getId();
	return lastId + 1;
}

AddTaskCommand::AddTaskCommand(TaskManager& tm, MyString&& name, Date&& dueDate, MyString&& description) : Command(taskManager)
{
	this->name = std::move(name);
	this->dueDate = std::move(dueDate);
	this->description = std::move(description);
}

void AddTaskCommand::execute()
{
	std::cout << taskManager.getUser().has_value() << std::endl;


	if (!taskManager.getUser().has_value())
		throw std::invalid_argument("There is no user logged in the system");

	const Vector<Task>& tasks = taskManager.getUser().value().getTasks();
	
	for (int i = 0; i < tasks.getSize(); i++)
	{
		if (name == tasks[i].getTaskName() && tasks[i].getDueDate() == dueDate)
			throw std::invalid_argument("Task already exists");
	}

	unsigned taskId = generateNextId(tasks);

	taskManager.setUserTask(Task(taskId, std::move(name), std::move(dueDate), std::move(description)));

	/*Task newTask(taskId, name, dueDate, description);
	newTask.setStatus(Status::ON_HOLD);
	tasks.pushBack(std::move(newTask))*/;
}
