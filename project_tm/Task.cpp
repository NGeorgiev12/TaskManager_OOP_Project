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

void Task::setTaskName(MyString&& newName)
{
	taskName = std::move(newName);
}

void Task::setDescription(const MyString& newDesc)
{
	description = newDesc;
}

void Task::setDescription(MyString&& newDesc)
{
	description = std::move(newDesc);
}

void Task::setStatus(Status newStatus)
{
	status = newStatus;
}

void Task::setDate(const Date& date)
{
	this->dueDate = date;
}

void Task::setDate(Date&& date)
{
	this->dueDate = std::move(date);
}

Task::Task(unsigned id, MyString&& name, Optional<Date>&& dueDate, MyString&& desc, Status status)
{
	this->id = id;
	this->taskName = std::move(name);
	this->dueDate = std::move(dueDate);
	this->description = std::move(desc);
	this->status = status;
}

Task::Task(unsigned id, MyString&& name, Date&& dueDate, MyString&& desc)
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

void Task::saveToBinary(std::ofstream& ofs) const
{
	ofs.write(reinterpret_cast<const char*>(&id), sizeof(unsigned));

	taskName.saveToBinary(ofs);

	if (!dueDate.has_value())
	{
		bool temp = false;
		ofs.write(reinterpret_cast<const char*>(&temp), sizeof(bool));
	}
	else
	{
		bool temp = true;
		ofs.write(reinterpret_cast<const char*>(&temp), sizeof(bool));
		(*dueDate).saveToBinary(ofs);
	}

	ofs.write(reinterpret_cast<const char*>(&status), sizeof(Status));

	description.saveToBinary(ofs);
}

void Task::loadFromBinary(std::ifstream& ifs)
{
	ifs.read(reinterpret_cast<char*>(&id), sizeof(unsigned));

	taskName.loadFromBinary(ifs);

	bool hasValue = 0;
	ifs.read(reinterpret_cast<char*>(&hasValue), sizeof(bool));
	if (hasValue)
	{
		Date date;
		date.loadFromBinary(ifs);

		Optional<Date> temp(std::move(date));
		
		dueDate = temp;
	}

	ifs.read(reinterpret_cast<char*>(&status), sizeof(Status));
	
	description.loadFromBinary(ifs);
}



