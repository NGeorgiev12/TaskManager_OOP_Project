#pragma once
#include "Task.h"
#include "Vector.hpp"
#include "Date.h"

class DashBoard
{
public:
	DashBoard() = default;
	DashBoard(const Vector<unsigned>& taskIds, const Date& date);
	const Vector<unsigned>& getTaskIds() const;
	const Date& getCurrentDate() const;
	void freeTaskIds();
	void addTaskId(unsigned id);
	void removeTaskId(unsigned id);
	void saveToBinary(std::ofstream& ofs) const;
	void loadFromBinary(std::ifstream& ifs);

private:
	Vector<unsigned> taskIds;
	Date currentDate;

	unsigned findTaskIdIndex(unsigned id) const;
};

