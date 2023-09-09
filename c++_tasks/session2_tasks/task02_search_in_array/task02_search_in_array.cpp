#include <array>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>

void search_in_arryay(int arr[],int size,int element)
{
    // use std::find to search for elemnt in the array giving the start and end of the array and the required element 
  int *elememt_ptr=std::find(arr,arr+size,element);

    // use std::distance to find the index of the elemnt giving the start of the array and the pointer of the element
  int index=std::distance(arr,elememt_ptr);

   // if the distance equals the size of the array means that reach the end without finding the element
  if(index==size)
  {
    std::cout<<"not found"<<std::endl;

  }
  else
  {
    std::cout<<"found in: "<<index<<std::endl;

  }
}

int main ()
{

const int size=6;
int arr[size]={15,10,6,-1,4,0};
int element;
std::cout<<"enter element to search for: ";
std::cin>>element;

search_in_arryay(arr,size, element);


}