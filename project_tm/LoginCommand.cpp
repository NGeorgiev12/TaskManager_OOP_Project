#include "LoginCommand.h"

LoginCommand::LoginCommand(TaskManager& taskMan, MyString&& username, MyString&& password) : Command(taskMan)
{
	this->username = std::move(username);
	this->password = std::move(password);
}

void LoginCommand::execute()
{

	for (int i = 0; i < taskManager.getUsers().getSize(); i++)
	{
		if (taskManager.getUsers()[i].getUsername() == username)
		{
			if (taskManager.getUsers()[i].getPassword() == password)
			{
				taskManager.setCurrentUserId(i);
				std::cout << "Welcome back, " << username << '!' << std::endl;
				return;
			}
			throw std::invalid_argument("Invalid password!");
			return;
		}
	}

	throw std::invalid_argument("Invalid username!");
}
