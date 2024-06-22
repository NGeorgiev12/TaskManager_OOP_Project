#include "RegisterCommand.h"

RegisterCommand::RegisterCommand(TaskManager& taskManager, MyString&& username, MyString&& password) : Command(taskManager)
{
	this->username = std::move(username);
	this->password = std::move(password);
}

void RegisterCommand::execute()
{
	MyString fileName(taskManager.getName());
	fileName += "Users.dat";

	std::ifstream ifs(fileName.c_str(), std::ios::binary | std::ios::in);

	if (!ifs.is_open())
	{
		std::ofstream ofs(fileName.c_str(), std::ios::binary | std::ios::out);

		username.saveToBinaryFile(ofs);
		password.saveToBinaryFile(ofs);

		std::cout << "Registered successfully!\n";
		return;
	}

	Vector<MyString> users;
	while (!ifs.eof())
	{
		MyString temp;
		temp.loadFromBinaryFile(ifs);
		users.pushBack(std::move(temp));
	}

	ifs.clear();
	ifs.close();

	for (int i = 0; i < users.getSize(); i++)
	{
		std::cout << users[i] << std::endl;
		
		if (users[i] == username)
			throw std::invalid_argument("User already registered");
	}

	std::ofstream ofs(fileName.c_str(), std::ios::binary | std::ios::out | std::ios::app);
	username.saveToBinaryFile(ofs);
	password.saveToBinaryFile(ofs);

	std::cout << "Registered successfully!1\n";
}
