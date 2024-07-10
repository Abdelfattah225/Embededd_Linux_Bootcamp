// 1.dependency.
#include<iostream>
#include<string>
#include<array>
/*****************************************************************/

// declarition
constexpr int No_of_persons = 4;
int No_of_person = 0;
bool IsRunning =true ; 

/*****************************************************************/
/* func.
    -input string
    -output nothing

*/
void print(std::string msg)
    {
        std::cout<<msg;
    }

class record
{
    public:
    // 1.data members.
       int age ;
       std::string  name ;
       int ID = 0 ;
    // 2.members function.  
    void show()
    {
        print("1: Add record \n");
        print("2: Fetch record \n");
        print("3: Quit \n \n");
        print("Enter option : ");

    }


};
enum class option
{
    Add = 1 , Fetch = 2 , Quit=3
};





  record person[No_of_persons];
  
/* func.
    -input nothing
    -output nothing

*/
void Add_User()
    {
        print("Add User. Plz enter user name and age:\n");
        print("Name: ");
        std::cin>>person[No_of_person].name;
         print("Age: ");
        std::cin>>person[No_of_person].age;
        print("\n");
        print("User record added successfully. \n\n");
        No_of_person++;

    }


/* func.
    -input nothing
    -output nothing

*/
void Fetch_User()
    {
        int search_id ;
        print("Plz enter user ID:\n");
        print("User ID: ");
        std::cin>>search_id;
        print("User name :"+person[search_id].name+"\n");
        print("User age :"+std::to_string(person[search_id].age)+"\n\n");
    }

void Quit_User()
{
    IsRunning=false;
}
constexpr int INIT_OPTION = 0;

/*********************************main func.*****************************/

int main()
{
    // declarition
int int_option = INIT_OPTION;
record ShowRecord ;


// code
//menu

print("User SignUp Application \n \n");
while (IsRunning==true)
{
    ShowRecord.show();
    std::cin>>int_option;
    print("\n");

    option op = static_cast<option>(int_option);

    // select option
    switch (op)
    {
        case option::Add:
            Add_User();
            break;
        case option::Fetch:
            Fetch_User();
            break;
        case option::Quit:
            Quit_User();
            break;    
        default:
            print("In Valid option \n");
            break;
    }
}







}