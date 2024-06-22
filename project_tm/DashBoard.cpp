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
