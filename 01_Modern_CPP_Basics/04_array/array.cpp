#include<iostream>
#include<array>


int main()
{
    std::array<int,5> number {1,2,3,4,5};

number.fill(0);

    std::cout<<number.front()<<std::endl;

    if (number.empty()==false)
    {
        std::cout<<"Not Empty \n";
    }

}