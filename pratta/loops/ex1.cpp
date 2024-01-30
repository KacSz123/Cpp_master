/*!
 * @file ex1.cpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief loops
 * @version 0.1
 * @date 2023-01-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<iostream>
int main()
{

    for(int i=0,j=10; i<10; ++i,--j){
        std::cout<<i<<", "<<j<<" ";
        std::cout<<i*j<<" \n";
        }
    std::cout<<std::endl;
    ///////

    std::cout << "\n\nSection II\n";
    (1>3)?std::cout<<1:std::cout<<2;
    std::cout<<std::endl;
    return 0;
}