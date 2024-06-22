#pragma once
#include "TaskPrinter.h"
class SimpleTaskPrinter : public TaskPrinter
{
public:
	static SimpleTaskPrinter& getInstance();
	void print(const Task& task) const override;
};

