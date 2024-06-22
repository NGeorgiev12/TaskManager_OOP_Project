#pragma once
#include "Task.h"
#include "Vector.hpp"
#include "Date.h"

class DashBoard
{
public:
	const Vector<unsigned>& getTaskIds() const;
	const Date& getCurrentDate() const;

private:
	Vector<unsigned> taskIds;
	Date currentDate;
};

