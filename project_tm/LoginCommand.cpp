#include "LoginCommand.h"

LoginCommand::LoginCommand(TaskManager& taskMan, MyString&& username, MyString&& password) : Command(taskMan)
{
	this->username = std::move(username);
	this->password = std::move(password);
}

void LoginCommand::execute()
{
	MyString fileName(taskManager.getName());
	fileName += "Users.dat";

	std::ifstream ifs(fileName.c_str(), std::ios::binary | std::ios::in);

	if (!ifs.is_open())
		throw std::invalid_argument("User is not in the system");

	Vector<MyString> users;
	while (!ifs.eof())
	{
		MyString temp;
		temp.loadFromBinaryFile(ifs);
		users.pushBack(std::move(temp));
	}

	ifs.clear();
	ifs.close();

	for (int i = 0; i < users.getSize(); i+=2)
	{
		if (users[i] == username)
		{
			if (users[i + 1] == password)
			{
				taskManager.setUser(User()); //!!!!!
				// da se zaredi v taskmanagera !!!!!!!!!!!!! 
				std::cout << "Welcome back, " << username << '!' << std::endl;
				return;
			}
			throw std::invalid_argument("Invalid password");
			return;
		}
	}

	throw std::invalid_argument("Invalid username");
}
