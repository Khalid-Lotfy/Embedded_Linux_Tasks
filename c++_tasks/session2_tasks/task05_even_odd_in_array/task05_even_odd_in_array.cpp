#include <algorithm>
#include <array>
#include <iostream>


int main ()
{

 std::array<int, 6>arr={15,2,3,10,0,5};
  int size= arr.size();


for(int i=0;i<size;++i)
{
  if(arr[i]%2==0)
  {
     std::cout<<arr[i]<<" is even  "<<std::endl; 
  }
  else
  {
    std::cout<<arr[i]<<" is odd  "<<std::endl;
    
  }
}



}