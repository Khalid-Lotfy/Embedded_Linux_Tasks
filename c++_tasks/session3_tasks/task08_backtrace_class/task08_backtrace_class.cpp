#include <iostream>
#include <list>

#define EnterFn  Backtrace b(__PRETTY_FUNCTION__)
#define PRINT_BT Backtrace::print_backtrace()

class Backtrace
{

public:
Backtrace(std::string name):name(name)
{
    list.push_back(this->name);
    std::cout<<"Enter "<<name<<std::endl;

}

~Backtrace()
{
    std::cout<<"Exit "<<name<<std::endl;
}

static void print_backtrace()
{
    int j=0;
    std::cout<<std::endl<<"Backtrace as follows: "<<std::endl;
    for( std::string i:list)
    {
        std::cout<<j<<"- "<<i<<std::endl;
        ++j;
    }
    std::cout<<"Backtrace is finished. "<<std::endl<<std::endl;
}

private:
  std::string name;
  static std::list<std::string> list;


    
};


std::list<std::string> Backtrace::list={};

void fun3()
{
   EnterFn;
   PRINT_BT;
  

}
void fun2()
{

  EnterFn;
  fun3();

}

void fun1()
{
  EnterFn;
  fun2();

}



int main()
{

EnterFn;
fun1();




}