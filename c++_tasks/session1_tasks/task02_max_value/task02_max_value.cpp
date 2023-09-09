#include <algorithm>
#include <iostream>

// use std::max to calculate the max between 3 values
int main ()
{
   int x,y,z;
   int max;
   std::cout<<"enter three values: "<<std::endl;
   std::cin>>x>>y>>z;
   max=std::max(x,y);
   max=std::max(max,z);
   std::cout<<"Maximum value is: "<<max<<std::endl;


}