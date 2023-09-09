#include <iostream>


int main()
{
int num;
std::cout<<"enter number: ";
std::cin>>num;

 auto square=[](int num)
 {
   

   return num*num;

 };

 
std::cout<<"square of a number is: "<<square(num)<<std::endl;

}