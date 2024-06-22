#include "UpdateTaskNameCommand.h"

UpdateTaskNameCommand::UpdateTaskNameCommand(TaskManager& taskMan, unsigned id, MyString&& name) : Command(taskMan)
{
	setId(id);
	setName(std::move(name));
}

void UpdateTaskNameCommand::setId(unsigned id)
{
	this->id = id;
}

void UpdateTaskNameCommand::setName(MyString&& name)
{
	this->name = std::move(name);
}

void UpdateTaskNameCommand::execute()
{
	if (!taskManager.getUser().has_value())
		throw std::invalid_argument("There is no user logged in the system");


}

unsigned UpdateTaskNameCommand::getId() const
{
	return id;
}

const MyString& UpdateTaskNameCommand::getName() const
{
	return name;
}
