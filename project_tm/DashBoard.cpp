#include "DashBoard.h"

const Vector<unsigned>& DashBoard::getTaskIds() const
{
	return taskIds;
}

const Date& DashBoard::getCurrentDate() const
{
	return currentDate;
}
