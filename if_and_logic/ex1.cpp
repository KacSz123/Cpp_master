/*!
 * @file ex1.cpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief cctype 
 * @version 0.1
 * @date 2023-01-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<cctype>
int main()
{
    if (isalpha('a'))
        std::cout<<"a to litera!\n";
    if (isdigit('7'))
        std::cout<<"7 to cyfra!\n";
    if (isspace(' '))
        std::cout<<"' ' to spacja!\n";
    if (ispunct(','))
        std::cout<<", to znak interpunkcyjny!\n";
    return 0;
}