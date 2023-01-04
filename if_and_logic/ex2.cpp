/*!
 * @file ex2.cpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief read from and write into file
 * @version 0.1
 * @date 2023-01-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
#include<fstream>

int main()
{
    std::fstream file;
    file.open("data.txt");
    int data=0;
    while((file>>data).good())
    {
        
        std::cout<<data<<" ";}

    std::cout<<"\n";
    return 0;
}