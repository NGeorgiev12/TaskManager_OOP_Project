#include "Date.h"
#include <iostream>
#include <sstream>

static bool isDigit(char ch)
{
	return (ch - '0' >= 0 && ch - '0' <= 9);
}

Date::Date(unsigned day, unsigned month, unsigned year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

Date::Date(const MyString& timeStr)
{
	std::stringstream ss(timeStr.c_str());
	char buff[64];

	ss.getline(buff, 64, '-');
	year = atoi(buff);

	ss.getline(buff, 64, '-');
	month = atoi(buff);

	ss.getline(buff, 64, '-');
	day = atoi(buff);
	if (!validStringDate(buff))
		throw std::invalid_argument("Invalid data, should include only digits and hyphen sign");

	validateDate();
}

unsigned Date::getDay() const
{
	if (!good()) throw std::invalid_argument("Date::getDay() Invalid day");
	return day;
}
unsigned Date::getMonth() const
{
	if (!good()) throw std::invalid_argument("Date::getMonth() Invalid day");
	return month;
}
unsigned Date::getYear() const
{
	if (!good()) throw std::invalid_argument("Date::getYear() Invalid day");
	return year;
}

void Date::setYear(unsigned year)
{
	if (!good()) throw std::invalid_argument("Date::getDay() Invalid day");

	this->year = year;
	if (isLeapYear())
		MAX_DAYS[1] = 29;
	else
		MAX_DAYS[1] = 28;

	isModified = true;
	validateDate();
}

void Date::setDay(unsigned day)
{
	if (!good()) throw std::invalid_argument("Date::getMonth() Invalid day");
	this->day = day;
	isModified = true;
	validateDate();
}
void Date::setMonth(unsigned month)
{
	if (!good()) return;
	this->month = month;
	isModified = true;
	validateDate();
}

void Date::goToNextDay()
{
	if (!good()) return;
	if (year == 1916 && month == 3 && day == 31) //Julian to the Gregorian calendar
	{
		day = 14;
		month = 4;
	}
	else
	{
		day++;
		if (day > MAX_DAYS[month - 1])
		{
			day = 1;
			setMonth(month == 12 ? 1 : (month + 1));
			if (month == 1)
				setYear(year + 1);
		}
	}
	isModified = true;
}

//int Date::getDayOfWeek() const
//{
//	if (!good()) return -1;
//	if (!isModified)
//		return dayOfWeek;
//
//	Date d(1, 1, 1);
//	int day = 5; //0 for monday, 6 for sunday (We know that 1.1.1 is saturday)
//
//	while (compareDates(d, *this) != 0)  //very simple (but dumb) algorithm
//	{
//		d.goToNextDay();
//		day++;
//		day %= 7;
//	}
//	dayOfWeek = day + 1; //1 for monday, 7 fo sunday
//	isModified = false;
//	return dayOfWeek;
//}

void Date::print() const
{
	if (!good()) return;
	std::cout << day << "." << month << "." << year << std::endl;
}

bool Date::isLeapYear() const
{
	if (year <= 1916)
		return year % 4 == 0;
	else
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Date::validateDate()
{
	isDateInValidState = !((month == 0 || month > 12) ||
		(day == 0 || day > MAX_DAYS[month - 1]) ||
		(year == 0) ||
		(year == 1916 && month == 4 && day < 14)); //(due to the transition of Julian to Gregorian)
	//we don't create an object here, because we are calling this func in the constructor(an inf recursion)
}

bool Date::validStringDate(const char* buff) const
{
	if (!buff)
		throw std::runtime_error("Nullpointer check for dateString");

	for (int i = 0; i < strlen(buff); i++)
	{
		if (!isDigit(buff[i]) && buff[i] != '-')
			return false;
	}
	return true;
}


bool Date::good() const //all functions should check this in the beggin!
{
	return isDateInValidState;
}

void Date::clear()
{
	isDateInValidState = true;
	day = month = year = 1;
}

void Date::saveToBinary(std::ofstream& ofs) const
{
	ofs.write(reinterpret_cast<const char*>(&year), sizeof(unsigned));
	ofs.write(reinterpret_cast<const char*>(&month), sizeof(unsigned));
	ofs.write(reinterpret_cast<const char*>(&day), sizeof(unsigned));
}

void Date::loadFromBinary(std::ifstream& ifs)
{
	ifs.read(reinterpret_cast<char*>(&year), sizeof(unsigned));
	ifs.read(reinterpret_cast<char*>(&month), sizeof(unsigned));
	ifs.read(reinterpret_cast<char*>(&day), sizeof(unsigned));
}

//int compareDates(const Date& lhs, const Date& rhs)
//{
//	if (lhs.getYear() < rhs.getYear())
//	{
//		return -1;
//	}
//	else if (lhs.getYear() > rhs.getYear())
//	{
//		return 1;
//	}
//	else
//	{ // years are equal, compare months
//		if (lhs.getMonth() < rhs.getMonth())
//		{
//			return -1;
//		}
//		else if (lhs.getMonth() > rhs.getMonth())
//		{
//			return 1;
//		}
//		else
//		{ // months are equal, compare days
//			if (lhs.getDay() < rhs.getDay())
//			{
//				return -1;
//			}
//			else if (lhs.getDay() > rhs.getDay())
//			{
//				return 1;
//			}
//			else
//			{
//				return 0; // All are equal
//			}
//		}
//	}

//}

bool operator==(const Date& lhs, const Date& rhs)
{
	return !(lhs < rhs) && !(rhs < lhs);
}

bool operator!=(const Date& lhs, const Date& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (!lhs.good())
		throw std::invalid_argument("LHS date is invalid");

	if (!rhs.good())
		throw std::invalid_argument("RHS date is invalid");

	if (lhs.getYear() > rhs.getYear())
		return false;
	else if (lhs.getYear() == rhs.getYear())
	{
		if (lhs.getMonth() > rhs.getMonth())
			return false;
		else if (lhs.getMonth() == rhs.getMonth())
			if (lhs.getDay() >= rhs.getDay())
				return false;
	}

	return true;
}

bool operator>=(const Date& lhs, const Date& rhs)
{
	return !(lhs < rhs);
}

bool operator>(const Date& lhs, const Date& rhs)
{
	return (lhs >= rhs) && (lhs != rhs);
}

bool operator<=(const Date& lhs, const Date& rhs)
{
	return !(lhs > rhs);
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();
	return os;
}

