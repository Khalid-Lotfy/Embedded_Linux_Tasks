#include <iostream>

// take three sides of triangle and returns if they form a right angle triangle or not
int main ()
{
  
 float a,b,c;
do {
 std::cout<<"please enter three integral vlaues greater than 0: "<<std::endl;
 std::cin>>a>>b>>c;
}while ((a<=0) || (b<=0) || (c<=0) );

if((a*a+b*b==c*c) || (a*a+c*c==b*b) || (b*b+c*c==a*a))
{
    std::cout<<"Your values form a right angle triangle "<<std::endl;

}
else 
{
   std::cout<<"Your values don't form a right angle triangle "<<std::endl;

}

}