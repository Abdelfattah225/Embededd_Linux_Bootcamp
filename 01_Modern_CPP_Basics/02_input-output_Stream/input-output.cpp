/*

Get username and age form input stream
Print "Hello {username} you age is {age}"
 
 */

#include <iostream>
#include <string>

int main ()
{
    std::string name;
    int age = 0;

// output stream
    std::cout<<"Enter your name : "<<std::endl;
    std::cin>>name;  // input stream

    std::cout<<"Enter your age : "<<std::endl;
    std::cin>>age;

    std::cout<<"Hello "<<name<<", you age is "<<age;

}