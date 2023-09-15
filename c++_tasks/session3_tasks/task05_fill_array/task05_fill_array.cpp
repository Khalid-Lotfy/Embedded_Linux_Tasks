#include <array>
#include <iostream>
#include <numeric>


int main()
{

std::array<int, 9991>arr ={};

std::iota(arr.begin(), arr.end(), 10); //fill_array_sequentially

for(int i :arr)
{
    std::cout<<i<<std::endl;
}
}