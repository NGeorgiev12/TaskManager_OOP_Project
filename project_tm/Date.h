#pragma once
#include "MyString.h"
#include <fstream>
#include <ctime>

class Date
{
public:
	Date() = default;
	Date(unsigned day, unsigned month, unsigned year);
	Date(const MyString& timeStr);
	unsigned getDay() const;
	unsigned getMonth() const;
	unsigned getYear() const;

	void setDay(unsigned day);
	void setMonth(unsigned month);
	void setYear(unsigned year);

	void print() const;
	void goToNextDay();
	//int getDayOfWeek() const;

	bool good() const;
	void clear();
	friend bool operator==(const Date& lhs, const Date& rhs);
	friend bool operator!=(const Date& lhs, const Date& rhs);
	friend bool operator<(const Date& lhs, const Date& rhs);
	friend bool operator>=(const Date& lhs, const Date& rhs);
	friend bool operator>(const Date& lhs, const Date& rhs);
	friend bool operator<=(const Date& lhs, const Date& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Date& date);

private:
	unsigned MAX_DAYS[12] = { 31,28,31,30,31, 30, 31, 31, 30, 31, 30, 31 };
	unsigned day = 1;
	unsigned month = 1;
	unsigned year = 1;

	bool isLeapYear() const;
	void validateDate();
	bool validStringDate(const char* buff) const;
	bool isDateInValidState = true;
	mutable bool isModified = true;
	mutable int dayOfWeek = -1;
};

