
#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>



int main()
{

std::array<int, 5>arr;
std::fill(arr.begin(),arr.end(),5);

int count=std::accumulate(arr.begin(),arr.end(),0);

std::cout<<count<<std::endl;




}