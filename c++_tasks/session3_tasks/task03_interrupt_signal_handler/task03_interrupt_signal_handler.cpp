#include <csignal>
#include <iostream>

void interrupt_handler(int signal)
{

std::cout<<"the program terminates with interrupt signal ctrl+c  exiting....."<<std::endl;


exit(signal);

}

int main()
{

 std::signal(SIGINT,interrupt_handler);

 while (true)
 {
   std::cout<<"waiting for singnal"<<std::endl;

 }



}

