// project_tm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CommandFactory.h"

void run(TaskManager& tm)
{
	MyString str;
	while (true)
	{
		try
		{
			std::cin >> str;
			Command* cmd = CommandFactory::makeCommand(tm, str);
			cmd->execute();
			delete cmd;

			if (str == "exit")
				break;
				
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
int main()
{
	
	TaskManager tm3("TaskManager1.dat");
	run(tm3);
	
}
