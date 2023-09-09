#include <iostream>

int main()
{
  for(int i=2;i<13;++i )
  {
    std::cout<<"multiplication table of : "<<i<<std::endl;
    for (int j=2; j<13; ++j) 
    {

      std::cout<<i<<" x "<<j<<" = "<<i*j<<std::endl;

    
    }
    std::cout<<"====================================="<<std::endl;
  }

}