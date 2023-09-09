#include <algorithm>
#include <array>
#include <iostream>


int main ()
{

 std::array<int, 6>arr1={15,2,3,-1,0,5};
  int size1= arr1.size();

  std::array<int, 6>arr2={10,15,20,100,0,3};
  int size2= arr2.size();

  const int merged_size =size1+size2;
  int merged_array[merged_size];
  
  std::copy(arr1.begin(),arr1.end(),merged_array);
  std::copy(arr2.begin(),arr2.end(),merged_array+size1);

for(int i=0;i<merged_size;++i)
{
 std::cout<<merged_array[i]<<"  "; 
}

std::cout<<std::endl;



}