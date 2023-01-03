/*!
 * @file ex4.cpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief some code with Unions and enums
 * @version 0.1
 * @date 2023-01-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
union mojaUnia
{
    int ID;
    long age;

};
int main()
{
    mojaUnia unia;
    unia.ID=2;
    unia.age=123;
    std::cout<<unia.age<<"    "<<unia.ID<<std::endl;
    return 0;
}