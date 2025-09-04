/**
 * @file lab3_3.cpp
 * @author David Espinoza
 * @brief program to read in seconds from user and convert to days, hours, mins, and seconds
 * @version 0.1
 * @date 2025-09-04
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
using namespace std;

int main()
{
    int seconds = 0,
            OGseconds = 0,
            remainder = 0,
            minutes = 0,
            hours = 0,
            days = 0;

    
    cout << "Enter a number of seconds: ";
    cin >> OGseconds; 

    days = OGseconds / 86400;
    remainder = OGseconds % 86400;
    hours = remainder / 3600;
    remainder = remainder % 3600;
    minutes = remainder / 60;
    seconds = remainder % 60; 

    cout << OGseconds << " is " << days << " days, " << hours << " hours, " << 
    minutes << " minutes, and " << seconds << " seconds." << endl;

    return 0;
}