#// 1.declare dependency
#include<iostream>
// 2.Extract Nouns: [menu optoins food price]
// 3.Extract Verbs: [select]

int main()
{
    bool IsRunning = true ;
    constexpr int FRIES_PRICE = 1;
    constexpr int BURGUR_PRICE= 2;
    constexpr int EXIT_OPTION = 3;


    constexpr int DEFAULT_OPTION= FRIES_PRICE;

    int option = DEFAULT_OPTION;
  
 for( ; IsRunning==true ;)
  {
     //4.code
    std::cout<<"Menu \n";
    std::cout<<"1.Fries \n";
    std::cout<<"2.Buger \n";
    std::cout<<"Plz select one of the optoins : \n";

    std::cin>>option;


    switch (option)
    {
    case FRIES_PRICE:
        {
            std::cout<<"Fries Price $1 \n";
        }
        break;
    
    case BURGUR_PRICE:
        {
            std::cout<<"Buger Price $2 \n";
        }
        break;
    case EXIT_OPTION:
        {
         IsRunning=false;   
        }
        break;    
    default:
        std::cout<<"Inv. option \n";
        break;
    }

  }
  
  
   

}