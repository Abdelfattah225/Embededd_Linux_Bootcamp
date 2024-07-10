
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




/*
    function: 
        -input : nothing.
        -output: option(int).
*/ 
int user_selet()
{
    int option = DEFAULT_OPTION;
    std::cin>>option;
    return option;
}


/////////////////////////// func. overloading ////////////////////////////
/*
    function: 
        -input : string.
        -output: nothing.
*/ 
void print_msg(std::string msg)
{
    std::cout << msg ;
}
/*
    function: 
        -input : string and intger.
        -output: nothing.
*/
void print_msg(std::string msg , int msg_number)
{
    std::cout << "msg number = " << msg_number << "msg content = " << msg << "\n";
}

int main()
{
   


    

    int option = DEFAULT_OPTION;
    int total_of_money_in_dollar=0;
    int total_of_money_in_Egy=0;
  while (IsRunning==true)
  {
     //4.code
    print_msg("Menu \n",1) ;
    print_msg("1.Fries \n") ;
    print_msg("2.Buger \n") ;
    print_msg("Plz select one of the optoins : \n") ;
    option = user_selet(); // select


    switch (option)
    {
    case FRIES_PRICE:
        {
            print_msg("Fries Price"+std::to_string(FRIES_PRICE)+"$ \n");
            total_of_money_in_dollar += FRIES_PRICE;
        }
        break;
    
    case BURGUR_PRICE:
        {
             print_msg("Buger Price"+std::to_string(BURGUR_PRICE)+"$ \n");
            total_of_money_in_dollar += BURGUR_PRICE;
        }
        break;
    case EXIT_OPTION:
        {
         IsRunning=false;  
        
         
         total_of_money_in_Egy=total_of_money_in_dollar*Dollar_to_pound;
         if(total_of_money_in_Egy>100)
         {
            print_msg("total price = "+std::to_string(total_of_money_in_Egy*.90)+"E \n");
         }
         else
         {
            print_msg("total price = "+std::to_string(total_of_money_in_Egy)+"E \n");
               
         }
        }
        break;    
    default:
        print_msg("Inv. option \n");
        break;
    }

  }
  
  
   

}