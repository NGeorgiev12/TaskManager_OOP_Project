#pragma once
#include "MyString.h"
#include "Optional.hpp"
#include "Date.h"
#include <ctime>
#pragma warning(disable : 4996)

enum class Status
{
	UNKNOWN,
	ON_HOLD,
	IN_PROCESS,
	DONE,
	OVERDUE
};

class Task
{
public:
	unsigned getId() const;
	const MyString& getTaskName() const;
	const Date& getDueDate() const;
	const Status& getStatus() const;
	const MyString& getDescription() const;

	void setId(unsigned newId);
	void setTaskName(const MyString& newName);
	void setStatus();
	void setDescription(const MyString& newDesc);

	Task(unsigned id, const MyString& name, const MyString& timeStr, const MyString& desc);
	Task(unsigned id, const MyString& name, const MyString& desc);
	bool isDueDateToday() const;

private:
	unsigned id = 0;
	MyString taskName;
	Optional<Date> dueDate;
	Status status = Status::UNKNOWN;
	MyString description;
};

