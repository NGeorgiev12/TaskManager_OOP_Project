// project_tm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Task.h"
#include "Date.h"
#include "TaskManager.h"
#include "User.h"
#include "RegisterCommand.h"
#include "LoginCommand.h"
#include "AddTaskCommand.h"

int main()
{
    /*Date d1("2024-10-13");
    Date d2("2024-10-12");
    std::cout << (d1 != d2);*/

    /*Task t(1, "OOP", "2024-06-16", "abab");
    std::cout << t.isDueDateToday();*/

    /*Date d1("2024-12-11");
    std::cout << d1.getYear() << std::endl;
    std::cout << d1.getMonth() << std::endl;
    std::cout << d1.getDay() << std::endl;*/
	/*std::ofstream ofs("users.dat", std::ios::binary);

	size_t usernameSize1 = 5, passwordSize1 = 7;
	MyString username1("ababa");
	MyString password1("mnmnaba");

	ofs.write(reinterpret_cast<const char*>(&usernameSize1), sizeof(size_t));
	ofs.write(reinterpret_cast<const char*>(username1.c_str()), sizeof(char) * usernameSize1);
	ofs.write(reinterpret_cast<const char*>(&passwordSize1), sizeof(size_t));
	ofs.write(reinterpret_cast<const char*>(password1.c_str()), sizeof(char) * passwordSize1);

	Vector<User> users;
	int counter = 0;
	std::ifstream ifs("users.dat", std::ios::binary);
	
	size_t usernameSize = 0, passwordSize = 0;
	ifs.read(reinterpret_cast<char*>(&usernameSize), sizeof(size_t));
	MyString username(usernameSize);
	char buff[64];
	ifs.read(reinterpret_cast<char*>(buff), sizeof(char) * usernameSize);
	ifs.read(reinterpret_cast<char*>(&passwordSize), sizeof(size_t));
	MyString password(passwordSize);
	ifs.read(reinterpret_cast<char*>(&password), sizeof(char) * passwordSize);
	users[counter].setPassword(password);
	users[counter].setUsername(username);

	std::cout << users[counter].getPassword() << " " << users[counter].getUsername() << std::endl;
	counter++;*/
	
	/*Date d1("2024-06-20");
	Date d2("2024-10-11");
	std::time_t t = time(0);
	std::tm* now = std::localtime(&t);
	std:: cout <<*/

	TaskManager tm("TM1");
	//Command* cmd = new RegisterCommand(tm, "Nik", "123");
//	cmd->execute();

	Command* cmd = new LoginCommand(tm, "Nikolay", "123");
	cmd->execute();

	Command* cmd1 = new AddTaskCommand(tm, "OOP1", Date("2024-06-23"), "ababa");
	cmd1->execute();
}
