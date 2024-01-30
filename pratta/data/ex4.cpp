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
void uniaFun()
{
        mojaUnia unia;
    unia.ID=2;
    unia.age=123;
    std::cout<<unia.age<<"    "<<unia.ID<<std::endl;
}
enum colours{red, green, blue, black, white};

void enumFun(colours colour)
{
    switch(colour)
    {
        case blue:
            std::cout<<"Can catch!\n";
            break;
        case green:
            std::cout<<"Can catch!\n";
            break;
              
        case red:
            std::cout<<"Can catch!\n";
            break;
        case black:
            std::cout<<"!!! Must not !!! catch!\n";
            break;
        case white:
            std::cout<<"Must catch! You'll earn extra life!\n";

    } 
    
}           
int main()
{
    uniaFun();

    enumFun(white);

    return 0;
}