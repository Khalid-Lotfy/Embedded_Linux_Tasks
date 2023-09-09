#include <iostream>

int main()
{

  unsigned int num,digit,sum=0;
  std::cout<<"enter an integer: ";
  std::cin>>num;
  while (num!=0)
  {
    digit=num%10;
    sum+=digit;
    num/=10;
   
  }
  std::cout<<"summation of digits is: "<<sum<<std::endl;
  
  


}