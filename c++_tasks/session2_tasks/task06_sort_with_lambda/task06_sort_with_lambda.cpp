#include <algorithm>
#include <iostream>
#include <iterator>





int main()
{

std::array<int,5> arr={5,10,-1,15,13};
int size=arr.size();

// sort with ascending order
std::sort(arr.begin(),arr.end(),[](int x,int y){return x<y;});

// print array 
std::cout<<"sorted array in ascending order"<<std::endl;
for(int i=0;i<size;++i)
{
 std::cout<<arr[i]<<"  "; 
}
std::cout<<std::endl;

// sort with descending order
std::sort(arr.begin(),arr.end(),[](int x,int y){return x>y;});

// print array 
std::cout<<"sorted array in descending order"<<std::endl;
for(int i=0;i<size;++i)
{
 std::cout<<arr[i]<<"  "; 
}
std::cout<<std::endl;


}