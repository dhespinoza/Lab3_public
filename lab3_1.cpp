/**
 * @file lab3_1.cpp
 * @author David Espinoza
 * @brief 
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
    int size = 0;    // The number of values to be averaged
    double num1 = 0.0,     // User input number 1
           num2 = 0.0,     // User input number 2
           average = 0.0;  // Average of num1 and num2

    // Get the two numbers
    cout << "Enter two numbers separated by one or more spaces: ";
    cin  >> num1 >> num2;

    // Calculate the average
    average = num1 + num2 / size;

    // Display the average
    cout << "The average of the two numbers is: " << average << endl;

    return 0;
}