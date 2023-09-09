#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>



class user
{
   
 public:
  static std::list<user*> address_book;  //list to store instances that will be created(users)
  // data about each user
  std::string name;
  std::string address;
  std::string phone;
  //default constructor
  user()
  { 
    
  }
  //param constructor  initiate the user data 
  user(std::string n,std::string add,std::string ph):name(n),address(add),phone(ph)
  {
      address_book.push_back(this);  //add the user to list
  }
 
//add new users
 static void add ()
  {
     std::string name,address,phone;
     std::cout<<"please enter name/address/phone for the user: ";
     std::getline(std::cin,name);
     std::getline(std::cin,address);
     std::getline(std::cin,phone);
     //use new to allocate memory dinamically for each new user(instance from the class)
     user* new_user = new user(name, address, phone);
   
  }

 // show all the stored contacts  
 static void list()
 {
  for (user* i:address_book) 
  {
    
     std::cout<<"name: "<<i->name<<"  "<<"address: "<<i->address<<"  "<<"phone: "<<i->phone<<std::endl;
  }

 }

  //delete a contact form the list
  static void delete_user()
  {
     std::string name;
     bool flag=0;
     user *temp;
     std::cout<<"please enter name you want to delete: ";
     std::getline(std::cin,name);
     //iterate on the contact list 
     for(user*i:address_book)
     {
        if(i->name==name)  // when finding the required name  store its address
        {
          temp=i;
          std::cout<<"user deleted successfully"<<std::endl;
          flag=1;
        } 
     }
     
     if(flag==0)
     {
        std::cout<<"name not found "<<std::endl;

     }
     else
     {
         address_book.remove(temp); //use the stored address to remove the contact from the list 
         delete temp;
         
     }
     
  }

  //delete all the list
  static void delete_all()
  {
   address_book.clear();
  }

  //search for a contact
  static void search()
  {
     std::string name;
     bool flag=0;
     std::cout<<"please enter name you want to search for: ";
      std::getline(std::cin,name);
      //iterate on the list
     for(user*i:address_book)
     {
        if(i->name==name) // when finding the name print all its information
        {
          std::cout<<"user found"<<std::endl;
          std::cout<<"name: "<<i->name<<"  "<<"address: "<<i->address<<"  "<<"phone: "<<i->phone<<std::endl;
          flag=1;
        } 
     }
     if(flag==0)
     {
        std::cout<<"name not found "<<std::endl;

     }
     
  }

};
std::list<user*> user::address_book;




int main()
{

std::cout<<"welcome to your favourite address book"<<std::endl;

std::string input;
do
{   // show user's options
    std::cout<<"============================================"<<std::endl;
    std::cout<<"|list        |list all users"<<std::endl;
    std::cout<<"|add         |list all users"<<std::endl;
    std::cout<<"|delete      |list all users"<<std::endl;
    std::cout<<"|delete all  |list all users"<<std::endl;
    std::cout<<"|search      |list all users"<<std::endl;
    std::cout<<"|close       |list all users"<<std::endl;
    std::cout<<"============================================"<<std::endl;

   std::getline(std::cin,input); //take the user's input
    
    // call the class function according to user's choice
    if(input=="list")
    {
        user::list();
    }
    else if(input=="add")
    {
        user::add();
    }
    else if(input=="delete")
    {
        user::delete_user();
    }
    else if(input=="delete all")
    {
        user::delete_all();
    }
    else if(input=="search")
    {
        user::search();
    }
    else if(input=="close")
    {
        break;
    }
    else
    {
    std::cout<<"pleade enter valid input"<<std::endl;

    }

} while(1);


}

