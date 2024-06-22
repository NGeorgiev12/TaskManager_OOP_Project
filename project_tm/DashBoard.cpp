#include "DashBoard.h"

DashBoard::DashBoard(const Vector<unsigned>& taskIds, const Date& date)
{
	this->taskIds = taskIds;
	this->currentDate = date;
}

const Vector<unsigned>& DashBoard::getTaskIds() const
{
	return taskIds;
}

const Date& DashBoard::getCurrentDate() const
{
	return currentDate;
}

void DashBoard::freeTaskIds()
{
	while (!taskIds.empty())
	{
		taskIds.popBack();
	}
}

void DashBoard::addTaskId(unsigned id)
{
	taskIds.pushBack(id);
}

void DashBoard::removeTaskId(unsigned id)
{
	unsigned idIndex = findTaskIdIndex(id);
	taskIds.erase(idIndex);
}

void DashBoard::saveToBinary(std::ofstream& ofs) const
{
	taskIds.saveToBinary(ofs);
	currentDate.saveToBinary(ofs);
}

void DashBoard::loadFromBinary(std::ifstream& ifs)
{
	taskIds.loadFromBinary(ifs);
	currentDate.loadFromBinary(ifs);
}

unsigned DashBoard::findTaskIdIndex(unsigned id) const
{
	for (int i = 0; i < taskIds.getSize(); i++)
	{
		if (taskIds[i] == id)
			return i;
	}
	throw std::invalid_argument("Invalid taskId!");
}
