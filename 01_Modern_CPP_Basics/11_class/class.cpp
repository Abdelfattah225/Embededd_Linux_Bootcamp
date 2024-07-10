
// 1.declare dependency
#include<iostream>
#include<string>
#include<array>

// 2.Extract Nouns: [menu optoins food price]
// 3.Extract Verbs: [select]
 bool IsRunning = true ;
  


std::istream& operator>>(std::istream & input_stream , option & result )
{
    int int_option;
    input_stream >> int_option; // intger
    // convert intger --->  option enum
    result = static_cast <option>(int_option);
    return input_stream; 

}

/*
    function: 
        -input : nothing.
        -output: option(optoin(enum)).
*/ 
option user_selet()
{
    option option = DEFAULT_OPTION;
    std::cin>>option;
    return option;
}
/*
    function: 
        -input : string.
        -output: nothing.
*/ 
void print_msg(const std::string msg)
{
    std::cout << msg ;
}






class Menu
{
    public:
    // variables(nouns) ---> Menus contain..? Options
    // Fucntions(verbs) ---> What do i need form menu ? Show it 
    void show()
    {
        print_msg("Menu \n") ;
        print_msg("1.Fries \n") ;
        print_msg("2.Buger \n") ;
        print_msg("Plz select one of the optoins : \n") ;
    }

};

enum class option
{
   FRIES = 1,
   BURGUR= 2 ,
   EXIT = 3
};







option DEFAULT_OPTION= option::FRIES;
constexpr int Dollar_to_pound = 50;
constexpr int FRIES_PRICE = 1 ;
constexpr int BURGUR_PRICE = 2 ;
int main()
{
    // create new object from menu class.
    Menu New_Menu;


    option option = DEFAULT_OPTION;
    int total_of_money_in_dollar=0;
    int total_of_money_in_Egy=0;
  while (IsRunning==true)
  {
     //4.code
     // Menu
     New_Menu.show();

    option = user_selet(); // select


    switch (option)
    {
    case option::FRIES:
        {
            print_msg("Fries Price"+std::to_string(FRIES_PRICE)+"$ \n");
            total_of_money_in_dollar += FRIES_PRICE;
        }
        break;
    
    case  option::BURGUR:
        {
             print_msg("Buger Price"+std::to_string(BURGUR_PRICE)+"$ \n");
            total_of_money_in_dollar += BURGUR_PRICE;
        }
        break;
    case option:: EXIT:
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