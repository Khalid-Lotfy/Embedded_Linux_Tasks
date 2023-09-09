#include <iostream>
#include <string>

//determine if a letter a vowel or not
int main (){

  std::string vowels="AEIOUaeiou";

  char letter,flag=0;
  
  std::cout<<"enter a letter: ";

  std::cin>>letter;

  for (int i: vowels) 
  {
    if(i==letter)
    { 
       std::cout<<letter<<"  is a vowel"<<std::endl;
       flag=1;
       break;
    }
      
  }
  if(flag==0)
  {
    std::cout<<letter<<"  is not a vowel"<<std::endl;
  }


}