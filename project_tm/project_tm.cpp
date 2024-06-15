// project_tm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Task.h"
#include "Date.h"


int main()
{
    /*Date d1("2024-10-13");
    Date d2("2024-10-12");
    std::cout << (d1 != d2);*/

    Task t(1, "OOP", "2024-06-16", "abab");
    std::cout << t.isDueDateToday();

    /*Date d1("2024-12-11");
    std::cout << d1.getYear() << std::endl;
    std::cout << d1.getMonth() << std::endl;
    std::cout << d1.getDay() << std::endl;*/

    
    
}
