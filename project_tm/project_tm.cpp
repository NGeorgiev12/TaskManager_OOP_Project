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
#include "ListTasksCommand.h"
#include "UpdateTaskNameCommand.h"
#include "StartTaskCommand.h"
#include "UpdateTaskDescrCommand.h"

int main()
{

	/*TaskManager tm;
	Command* cmd = new RegisterCommand(tm, "Niki", "123");
	cmd->execute();
	*/

	//std::ofstream ofs("TaskMan1.dat", std::ios::binary | std::ios::out);
	//tm2.saveToBinary(ofs);

	TaskManager tm2("TaskMan1.dat");
	Command* cmd = new LoginCommand(tm2, "Niki", "123");
	cmd->execute();

	//Command* cmd1 = new AddTaskCommand(tm2, "Task1!", Date("2024-06-23"), "Obeli kartofite.");

	Command* cmd2 = new ListTasksCommand(tm2);

	/*Command* cmd3 = new UpdateTaskNameCommand(tm2, 1, "TaskPesho");
	cmd3->execute();*/
	//cmd1 -> execute();
	
	/*Command* cmd4 = new StartTaskCommand(tm2, 1);
	cmd4->execute();*/

	Command* cmd5 = new UpdateTaskDescrCommand(tm2, 1, "Obeli patladganite");
	cmd5->execute();
	cmd2->execute();
	////Task task;
	/////*task.setDate(MyString("2020-12-12"));
	////task.setDescription(MyString("task 1 description"));
	////task.setId(12);
	////task.setStatus(Status::IN_PROCESS);
	////task.setTaskName(MyString("Task1!"));*/

	//////std::ofstream ofs("task1.dat", std::ios::binary | std::ios::out);

	////std::ifstream ifs("task1.dat", std::ios::binary | std::ios::in);

	////task.loadFromBinary(ifs);

	/////*std::cout << task.getTaskName() << std::endl;
	////std::cout << task.getId() << std::endl;
	////std::cout << task.getDescription() << std::endl;
	////std::cout << (int)task.getStatus() << std::endl;
	////std::cout << task.getDueDate() << std::endl;*/

	////Vector<unsigned> vec;
	////vec.pushBack(12);
	////vec.pushBack(123);

	////DashBoard dashboard(vec, Date(MyString("2022-03-21")));

	////Task task2;
	////task2.setDate(MyString("2013-01-11"));
	////task2.setDescription(MyString("task 2 description"));
	////task2.setId(14);
	////task2.setStatus(Status::IN_PROCESS);
	////task2.setTaskName(MyString("Task2!"));

	////Task task;
	////std::ifstream ifs("task1.dat", std::ios::binary | std::ios::in);
	////task.loadFromBinary(ifs);

	////Vector<Task> vecTasks;
	////vecTasks.pushBack(task);
	////vecTasks.pushBack(task2);

	////Vector<MyString> collabNames;
	////collabNames.pushBack(MyString("collab1"));
	////collabNames.pushBack(MyString("collab122"));

	//////User user1(MyString("Boris"), MyString("1234r5"), dashboard, vecTasks, collabNames);

	///*User user1;
	//std::ifstream ifs1("User1.dat", std::ios::binary | std::ios::in);
	//user1.loadUserFromBinary(ifs1);*/


	////std::cout << user1.getUsername() << std::endl;
	////std::cout << std::endl;

	////std::cout << user1.getPassword() << std::endl;
	////std::cout << std::endl;

	////std::cout << "Dashboard: " << std::endl;
	////
	////std::cout << user1.getDashBoard().getCurrentDate() << std::endl;
	////for (int i = 0; i < user1.getDashBoard().getTaskIds().getSize(); i++)
	////{
	////	std::cout << user1.getDashBoard().getTaskIds()[i] << std::endl;;
	////}
	////
	////std::cout << std::endl;

	////for (int i = 0; i < user1.getCollabNames().getSize(); i++)
	////{
	////	std::cout << user1.getCollabNames()[i] << std::endl;
	////}

	////std::cout << std::endl;

	////for (int i = 0; i < user1.getTasks().getSize(); i++)
	////{
	////	std::cout << user1.getTasks()[i].getTaskName() << std::endl;
	////	std::cout << user1.getTasks()[i].getId() << std::endl;
	////	std::cout << user1.getTasks()[i].getDescription() << std::endl;
	////	std::cout << (int)user1.getTasks()[i].getStatus() << std::endl;
	////	std::cout << user1.getTasks()[i].getDueDate() << std::endl;

	////	std::cout << std::endl;
	////}

	////CollaborationTask ct;
	///*ct.setDate(MyString("2021-12-12"));
	//ct.setDescription(MyString("collab task 1 description"));
	//ct.setId(124);
	//ct.setStatus(Status::IN_PROCESS);
	//ct.setTaskName(MyString("Collab Task1!"));
	//ct.setAssignee(MyString("Johnson"));*/

	///*std::ofstream ofs2("CollabTask.dat", std::ios::binary | std::ios::out);
	//ct.saveToBinary(ofs2);*/

	///*std::ifstream ifs2("CollabTask.dat", std::ios::binary | std::ios::in);
	//ct.loadFromBinary(ifs2);*/
	///*std::cout << ct.getTaskName() << std::endl;
	//std::cout << ct.getId() << std::endl;
	//std::cout << ct.getDescription() << std::endl;
	//std::cout << (int)ct.getStatus() << std::endl;
	//std::cout << ct.getDueDate() << std::endl;
	//std::cout << ct.getAssignee() << std::endl;*/

	///*Vector<CollaborationTask> vecCt;
	//vecCt.pushBack(ct);

	//CollaborationTask ct2;
	//ct2.setDate(MyString("2023-12-12"));
	//ct2.setDescription(MyString("collab task 2 description"));
	//ct2.setId(154);
	//ct2.setStatus(Status::IN_PROCESS);
	//ct2.setTaskName(MyString("Collab Task2!"));
	//ct2.setAssignee(MyString("Johnson2"));

	//vecCt.pushBack(ct2);

	//Vector<MyString> workGroup;
	//workGroup.pushBack(MyString("Pesh"));
	//workGroup.pushBack(MyString("Izak"));*/

	////Collaboration coll(workGroup, MyString("Ivan"), vecCt, MyString("Collab1"), 1);

	///*Collaboration coll;
	//std::ifstream ifs3("Collab.dat", std::ios::binary | std::ios::in);
	//coll.loadFromBinary(ifs3);*/


	////
	////std::cout << coll.getCreator() << std::endl;
	////std::cout << '\n';

	////std::cout << coll.getName() << std::endl;
	////std::cout << '\n';

	////std::cout << coll.getId() << std::endl;
	////std::cout << '\n';

	////for (int i = 0; i < coll.getWorkGroup().getSize(); i++)
	////{
	////	std::cout << coll.getWorkGroup()[i] << std::endl;
	////}
	////std::cout << '\n';

	////for (int i = 0; i < coll.getTasks().getSize(); i++)
	////{
	////	std::cout << coll.getTasks()[i].getTaskName() << std::endl;
	////	std::cout << coll.getTasks()[i].getId() << std::endl;
	////	std::cout << coll.getTasks()[i].getDescription() << std::endl;
	////	std::cout << (int)coll.getTasks()[i].getStatus() << std::endl;
	////	std::cout << coll.getTasks()[i].getDueDate() << std::endl;
	////	std::cout << coll.getTasks()[i].getAssignee() << std::endl;
	////	std::cout << '\n';
	////}
	////std::cout << '\n';

	//User user1;
	//std::ifstream ifs1("User1.dat", std::ios::binary | std::ios::in);
	//user1.loadUserFromBinary(ifs1);

	//Vector<User> users;
	//users.pushBack(user1);

	//Collaboration coll;
	//std::ifstream ifs3("Collab.dat", std::ios::binary | std::ios::in);
	//coll.loadFromBinary(ifs3);

	//Vector<Collaboration> collabs;
	//collabs.pushBack(coll);

	///*TaskManager tm(12, MyString("TaskManager Chetiri"), users, collabs);
	//std::ofstream ofs1("TestTM.dat", std::ios::binary | std::ios::out);
	//tm.saveToBinary(ofs1);*/
	//
	//TaskManager tm;
	//std::ifstream ifs5("TestTM.dat", std::ios::binary|std::ios::in);


	//tm.loadFromBinary(ifs5);

	//std::cout << tm.getCurrentUserId() << std::endl;
	//std::cout << std::endl;

	//std::cout << tm.getName() << std::endl;
	//std::cout << std::endl;

	//for (int i = 0; i < tm.getUsers().getSize(); i++)
	//{
	//	std::cout << tm.getUsers()[i].getUsername() << std::endl;
	//	std::cout << std::endl;

	//	std::cout << tm.getUsers()[i].getPassword() << std::endl;
	//	std::cout << std::endl;

	//	std::cout << "Dashboard: " << std::endl;

	//	std::cout << tm.getUsers()[i].getDashBoard().getCurrentDate() << std::endl;
	//	for (int i = 0; i < tm.getUsers()[i].getDashBoard().getTaskIds().getSize(); i++)
	//	{
	//		std::cout << tm.getUsers()[i].getDashBoard().getTaskIds()[i] << std::endl;;
	//	}

	//	std::cout << std::endl;

	//	for (int i = 0; i < tm.getUsers()[i].getCollabNames().getSize(); i++)
	//	{
	//		std::cout << tm.getUsers()[i].getCollabNames()[i] << std::endl;
	//	}

	//	std::cout << std::endl;

	//	for (int i = 0; i < tm.getUsers()[i].getTasks().getSize(); i++)
	//	{
	//		std::cout << tm.getUsers()[i].getTasks()[i].getTaskName() << std::endl;
	//		std::cout << tm.getUsers()[i].getTasks()[i].getId() << std::endl;
	//		std::cout << tm.getUsers()[i].getTasks()[i].getDescription() << std::endl;
	//		std::cout << (int)tm.getUsers()[i].getTasks()[i].getStatus() << std::endl;
	//		std::cout << tm.getUsers()[i].getTasks()[i].getDueDate() << std::endl;

	//		std::cout << std::endl;
	//	}

	//	for (int i = 0; i < tm.getCollabs().getSize(); i++)
	//	{
	//		std::cout << tm.getCollabs()[i].getCreator() << std::endl;
	//		std::cout << '\n';

	//		std::cout << tm.getCollabs()[i].getName() << std::endl;
	//		std::cout << '\n';

	//		std::cout << tm.getCollabs()[i].getId() << std::endl;
	//		std::cout << '\n';

	//		for (int i = 0; i < tm.getCollabs()[i].getWorkGroup().getSize(); i++)
	//		{
	//			std::cout << tm.getCollabs()[i].getWorkGroup()[i] << std::endl;
	//		}
	//		std::cout << '\n';

	//		for (int i = 0; i < tm.getCollabs()[i].getTasks().getSize(); i++)
	//		{
	//			std::cout << tm.getCollabs()[i].getTasks()[i].getTaskName() << std::endl;
	//			std::cout << tm.getCollabs()[i].getTasks()[i].getId() << std::endl;
	//			std::cout << tm.getCollabs()[i].getTasks()[i].getDescription() << std::endl;
	//			std::cout << (int)tm.getCollabs()[i].getTasks()[i].getStatus() << std::endl;
	//			std::cout << tm.getCollabs()[i].getTasks()[i].getDueDate() << std::endl;
	//			std::cout << tm.getCollabs()[i].getTasks()[i].getAssignee() << std::endl;
	//			std::cout << '\n';
	//		}
	//		std::cout << '\n';
	//	}
	//}
}
