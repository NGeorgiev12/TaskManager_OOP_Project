#pragma once
#include "TaskPrinter.h"
class SimpleTaskPrinter : public TaskPrinter
{
public:
	void print(const Task& task) const override;
};

