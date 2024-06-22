#include "User.h"
const char FILE_NAME[32] = "users.dat";

constexpr int MAX_INITIAL_ID = 1024;

//static const Date& getToday()
//{
//	std::time_t t = time(0);
//	std::tm* now = std::localtime(&t);
//
//	Date currentDay;
//	currentDay.setYear(now->tm_year + 1900);
//	currentDay.setMonth(now->tm_mon + 1);
//	currentDay.setDay(now->tm_mday);
//	return currentDay;
//}
const MyString& User::getUsername() const
{
    return username;
}

const MyString& User::getPassword() const
{
    return password;
}

void User::setUsername(const MyString& newUsername)
{
    username = newUsername;
}

void User::setPassword(const MyString& newPassword)
{
    password = newPassword;
}

//User::User(const MyString& username, const MyString& password)
//{
//    setUsername(username);
//    setPassword(password);
//	//modifyDashboard();
//}

void User::addTask(Task&& task)
{
	tasks.pushBack(std::move(task));
}

//void User::updateTask(int id, const MyString& name)
//{
//	int taskIndex = findTaskIndexById(id);
//	tasks[taskIndex].setTaskName(name);
//}

//void User::startTask(int id)
//{
//	if (isIdUnique(id))
//		throw std::invalid_argument("User::startTask There is no such taskId");
//
//	int taskIndex = findTaskIndexById(id);
//	tasks[taskIndex].setStatus(Status::IN_PROCESS);
//}
//
//void User::updateTaskDescription(int id, const MyString& newDescription)
//{
//	if (isIdUnique(id))
//		throw std::invalid_argument("User::updateTaskDescription There is no such taskId");
//
//	int taskIndex = findTaskIndexById(id);
//	tasks[taskIndex].setDescription(newDescription);
//}

const Vector<Task>& User::getTasks() const
{
	return tasks;
}

//void User::deleteTask(int id)
//{
//	if (isIdUnique(id))
//		throw std::invalid_argument("User::deleteTask There is no such taskId");
//
//	int taskIndex = findTaskIndexById(id);
//	tasks.erase(taskIndex);
//	regulateId();
//}

//void User::getTask(const MyString& name)
//{
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		if (tasks[i].getTaskName() == name)
//		{
//			printTask(tasks[i]);
//			return;
//			// id-тата нарастват последователно => ще се печата първото
//		}
//	}
//
//	throw std::invalid_argument("User::getTask Invalid taskName");
//}

//void User::getTask(int id)
//{
//	if (isIdUnique(id))
//		throw std::invalid_argument("User::getTaskById There is no such taskId");
//
//	int taskIndex = findTaskIndexById(id);
//	printTask(tasks[taskIndex]);
//}

//void User::listTasks(const Date& date)
//{
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		if (tasks[i].getDueDate() == date)
//			printTask(tasks[i]);
//	}
//}

//void User::listTasks()
//{
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		printTask(tasks[i]);
//	}
//}

//void User::listCompletedTasks()
//{
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		if (tasks[i].getStatus() == Status::DONE)
//			printTask(tasks[i]);
//	}
//}

//void User::listDashboard()
//{
//}

//void User::finishTask(int id)
//{
//	int taskIndex = findTaskIndexById(id);
//	tasks[taskIndex].setStatus(Status::DONE);
//}

//int User::findTaskIndexById(int id) const
//{
//	if (isIdUnique(id))
//		throw std::invalid_argument("User::findTaskIndexById There is no such taskId");
//
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		if (tasks[i].getId() == id)
//			return i;
//	}
//}

//void User::printTask(const Task& task) const
//{
//	std::cout << "Task name : " << task.getTaskName() << std::endl;
//	std::cout << "Task ID : " << task.getId() << std::endl;
//	std::cout << "Due Date : " << task.getDueDate() << std::endl;
//	std::cout << "Task name : " << task.getTaskName() << std::endl;
//}
//
//void User::regulateId()
//{
//	if (tasks[0].getId() == MAX_INITIAL_ID)
//	{
//		for (int i = 0; i < tasks.getSize(); i++)
//		{
//			int newId = tasks[i].getId() - MAX_INITIAL_ID + 1;
//			tasks[i].setId(newId);
//		}
//	}
//		
//}

//void User::modifyDashboard()
//{
//	for (int i = 0; i < tasks.getSize(); i++)
//	{
//		if (tasks[i].isDueDateToday() && !isTaskInDashBoard(tasks[i]))
//			dashboard.addTaskToDashboard(tasks[i].getId());
//
//		if (isTaskInDashBoard(tasks[i]) && (!tasks[i].isDueDateToday()))
//		{
//			dashboard.removeTaskFromDashBoard(tasks[i].getId());
//			tasks[i].setStatus(Status::OVERDUE);
//		}	
//	}
//}



//void User::addCurrentTaskToDashboard()
//{
//	for (int i = 0; i < )
//}

//void User::saveUserInBinary(std::ofstream& ofs)
//{
//    int passwordSize = password.getSize();
//    int usernameSize = username.getSize();
//
//}

//void User::addTask(const MyString& name, const Date& dueDate, const MyString& description) 
//{ 
//    // проверка за равни имена и равни дати
//    for (int i = 0; i < tasks.getSize(); i++)
//    {
//        if (name == tasks[i].getTaskName() && tasks[i].getDueDate() == dueDate)
//            throw std::invalid_argument("User::addTask Two equal tasks");
//    }
//
//    Task newTask()
//}

