/*!
 * @file ex2.cpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief loops part2
 * @version 0.1
 * @date 2023-01-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<iostream>


int main()
{
    double sth[5]{1.2,1.5,2.5,4.521,5.55};
    for (double x:sth)
        std::cout<<x<<", ";
    return 0;
}