#include <iostream>


int  &fun()
{

    static int z =0;
    std::cout<<z<<std::endl;
    return z;
}

int  fun2()
{

    static int z =0;
    std::cout<<z<<std::endl;
    return z;
}

int main()
{
    // assigning value 10 to the result of 'fun' function which is reference to static int 'z'
    // first time calling fun() it prints '0' 
    fun()=10;   
    // then the next calling of fun() will print value 10 becuase the pervious line assign 10 to reference of z
    fun();
   
  //  fun2()=10;  error because fun2 returns int not reference to int 

}