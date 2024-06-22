#include "Task.h"
#include <sstream>
#include <iostream>

unsigned Task::getId() const
{
	return id;
}

const MyString& Task::getTaskName() const
{
	return taskName;
}

const Date& Task::getDueDate() const
{
	if (!dueDate.has_value())
		throw std::invalid_argument("There is no deadline for the task");

	return dueDate.value();
}

const Status& Task::getStatus() const
{
	return status;
}

const MyString& Task::getDescription() const
{
	return description;
}

void Task::setId(unsigned newId)
{
	id = newId;
}

void Task::setTaskName(const MyString& newName)
{
	taskName = newName;
}

void Task::setDescription(const MyString& newDesc)
{
	description = newDesc;
}

void Task::setStatus(const Status& newStatus)
{
	status = newStatus;
}

//Task::Task(unsigned id, const MyString& name, const Date& timeStr, const MyString& desc) : dueDate(timeStr)
//{
//	setId(id);
//	setTaskName(name);
//	setDescription(desc);
//}

Task::Task(unsigned id, MyString&& name, Optional<Date>&& dueDate, MyString&& desc)
{
	this->id = id;
	this->taskName = std::move(name);
	this->dueDate = std::move(dueDate);
	this->description = std::move(desc);
}

Task::Task(unsigned id, const MyString& name, const MyString& desc)
{
	setId(id);
	setTaskName(name);
	setDescription(desc);
}

bool Task::isDueDateToday() const
{
	if (!dueDate.has_value())
		return false;

	std::time_t t = time(0);
	std::tm* now = std::localtime(&t);

	Date currentDay;
	currentDay.setYear(now->tm_year + 1900);
	currentDay.setMonth(now->tm_mon + 1);
	currentDay.setDay(now->tm_mday);

	return currentDay == dueDate.value();
}



