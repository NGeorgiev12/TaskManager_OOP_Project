#include "RegisterCommand.h"

RegisterCommand::RegisterCommand(TaskManager& taskManager, MyString&& username, MyString&& password) : Command(taskManager)
{
	this->username = std::move(username);
	this->password = std::move(password);
}

void RegisterCommand::execute()
{
	for (int i = 0; i <taskManager.getUsers().getSize(); i++)
	{
		
		if (taskManager.getUsers()[i].getUsername() == username)
			throw std::invalid_argument("User already registered!");
	}
	
	taskManager.addUser(User(std::move(username), std::move(password)));
	std::cout << "Registered successfully!\n";
}
