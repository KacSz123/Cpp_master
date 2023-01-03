/*!
 * @file ex3.cpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief some code with structure
 * @version 0.1
 * @date 2023-01-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
struct robot
{
    int ID;
    double weight;
    std::string name;
    std::string type;
};

void newRobot(int ID, double weight, std::string name,std::string type,robot *r)
{
    r->ID=ID;
    r->name=name;
    r->weight=weight;
    r->type=type;
}
void printRobot(robot * r)
{
    std::cout<<"ID: "<<r->ID<<"; name: "<<r->name<<" weight: "<<r->weight<<"kg; type: "<<r->type<<";\n";
}
int main()
{
    robot *r1,r3;
    r1=new robot;
    robot r2{2,1.23,"zlomek","ramie"};
    newRobot(1,12.85,"ziomek","dron",r1);
    r3=*r1;
    printRobot(r1);
    printRobot(&r2);
    printRobot(&r3);

    delete(r1);
    return 0;
}