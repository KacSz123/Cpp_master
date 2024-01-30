/*!
 * @file ex5.cpp
 * @author {Kacper Szczepanowski} ({kacperszcz159@gmail.com})
 * @brief some code with pointers -__,-
 * @version 0.1
 * @date 2023-01-03
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include<array>
#include<vector>
int main()
{
    std::cout << "\nSection I\n";
    int a = 1;
    int *p1 = &a;

    int *p2 = new int;
    int *p3 = new int[2];
    std::cout << "p1: " << p1 << ";   p2: " << p2 << ";   p3: " << p3 << ";\n";

    std::cout << "\n\nSection II\n";
    p1 = new int[10];
    for (int i = 0; i < 10; ++i)
    {
        p1[i] = i*20000;
        std::cout << p1[i] << "; ";
    }
    const char* str="siemasiema";
    std::cout<<"\n"<<str<<"  adres to (przez (int*))"<<(int*)str<<std::endl;
    std::cout<<"\n"<<str[5]<<std::endl;
    std::cout << std::endl;
    std::cout << *(p1 + 8) << std::endl;
    std::cout<< sizeof(int)<<std::endl;
    std::cout<< sizeof(p1)<<std::endl;
    delete[] p1;
    delete[] p3;
    delete[] p2;
    std::cout << "\n\nSection III\n";
    
     p1 = new int;
     p2 = new int;
     p3 = new int;
    
    int* tab[3];
    tab[0]=p1;
    tab[1]=p2;
    tab[2]=p3;
    std::cout<<"tab1 "<<tab[0]<<", tab2 "<<tab[1]<<" , tab3 "<<tab[2]<<std::endl;
    
    std::cout << "\n\nSection III\n";

    std::vector<int> vi;

    vi.push_back(4);
    vi.push_back(1);
    vi.push_back(1234);
    std::cout<<vi.size()<<std::endl;

    std::cout << "\n\nSection IV\n";
    std::array<int,3> arr{1,2,313};

    std::cout<<arr.size()<<"   "<<arr[2]<<std::endl;
    return 0;
}
