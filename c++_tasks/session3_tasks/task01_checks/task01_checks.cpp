//  check if the character is digit ? 
//  check if all the array is even ?
//  check if there is any value of array is even ?

#include <array>
#include <cctype>
#include <charconv>
#include <iostream>

#define size 5

bool are_all_even(int arr[],int s)
{
for (int i=0; i<size; ++i) 
{
   if(arr[i]%2 != 0)
   {
     return false;
   }
}

return true;

}

bool is_any_of_array_even(int arr[],int s)
{
for (int i=0; i<size; ++i) 
{
   if(arr[i]%2 == 0)
   {
     return true;
   }
}

return false;

}


int main ()
{

char ch ='0';
int arr[5]={2,4,6,8,10};
int arr2[5]={1,2,3,4,5};


bool digit_char=isdigit(ch);

bool all_even_array=are_all_even(arr, size);
bool even_in_array=is_any_of_array_even(arr2, size);

// use std::boolalpha to print bool as true or false not 0 and 1
std::cout<<"is the char digit?                 "<<std::boolalpha<<bool(digit_char)<<std::endl;
std::cout<<"are all the array is even?         "<<std::boolalpha<<all_even_array<<std::endl;
std::cout<<"is any value of array is even?     "<<std::boolalpha<<even_in_array<<std::endl;



}