#include <iostream>
#include <bitset>

// use bitset to convert decimal to binary and vice versa
int main ()
{
  int num1;
  std::bitset<32>num2;

  std::cout<<"enter dicimal number: ";
  std::cin>>num1;
  // assigning a decimal number to a bitset will store it in binary
  std::bitset<32> binary =(num1);
  std::cout<<"binary representaion : "<<binary<<std::endl;

  std::cout<<"enter binary number: ";
  std::cin>>num2;
  // use to ulong function from bitset to convert binary to dicimal
   std::cout<<"dicimal representaion : "<<num2.to_ulong()<<std::endl;
 


}