#pragma once
#include "Task.h"

class TaskPrinter
{
public:
	virtual void print(const Task& task) const = 0;
	virtual ~TaskPrinter() = default;
};

