// 1.declare dependency
#include<iostream>
// 2.Extract Nouns: [menu optoins food price]
// 3.Extract Verbs: [select]
 bool IsRunning = true ;
    constexpr int FRIES_PRICE = 1;
    constexpr int BURGUR_PRICE= 2;
    constexpr int EXIT_OPTION = 3;
constexpr int DEFAULT_OPTION= FRIES_PRICE;
 constexpr int Dollar_to_pound = 50;

int main()
{
   


    

    int option = DEFAULT_OPTION;
    int total_of_money_in_dollar=0;
    int total_of_money_in_Egy=0;
  while (IsRunning==true)
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
            std::cout<<"Fries Price"<< FRIES_PRICE <<"$ \n";
            total_of_money_in_dollar += FRIES_PRICE;
        }
        break;
    
    case BURGUR_PRICE:
        {
            std::cout<<"Buger Price"<<BURGUR_PRICE<<"$ \n";
            total_of_money_in_dollar += BURGUR_PRICE;
        }
        break;
    case EXIT_OPTION:
        {
         IsRunning=false;  
        
         
         total_of_money_in_Egy=total_of_money_in_dollar*Dollar_to_pound;
         if(total_of_money_in_Egy>100)
         {
                 std::cout<<"total price = "<< total_of_money_in_Egy*.90 ;
         }
         else
         {
                 std::cout<<"total price = "<< total_of_money_in_Egy;
         }
        }
        break;    
    default:
        std::cout<<"Inv. option \n";
        break;
    }

  }
  
  
   

}