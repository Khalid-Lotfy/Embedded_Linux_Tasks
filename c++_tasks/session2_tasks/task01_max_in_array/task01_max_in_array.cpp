#include <algorithm>
#include <iostream>
#include <iterator>

#define size  5


int max_in_array(int arr[],int s)
{
   int * ptr=std::max_element(arr,arr+size,[](int x,int y){return x<y;});
   return (*ptr) ;
}

int main()
{

int arr[size]={5,10,-1,15,13};


std::cout<<"maximum element in the array is: "<<max_in_array(arr, size)<<std::endl;


}