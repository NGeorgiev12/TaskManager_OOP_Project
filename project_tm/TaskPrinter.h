#pragma once
#include "Task.h"
#include "CollaborationTask.h"

class TaskPrinter
{
public:
	virtual void print(const Task& task) const = 0;
	virtual void print(const CollaborationTask& collabTask) const = 0;
	virtual ~TaskPrinter() = default;
};

