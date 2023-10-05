#include <cstddef>
#include <cstring>
#include<iostream>
#include <map>
#include <string>
#include <vector>


enum class LogLevel
{
   DEBUG,
   INFO,
   WARNING,
   ERROR

};



class LOG
{

private:
struct message
{
    std::string message;
    LogLevel level;

};

message msg;
static std::vector<message> bufffer;
std::map<LogLevel,std::string> enum_to_string{{LogLevel::DEBUG,"DEBUG"},
{LogLevel::ERROR,"ERROR"},{LogLevel::INFO,"INFO"},{LogLevel::WARNING,"WARNING"}};


public:
void add_message( std::string msg, LogLevel lvl )
{
    this->msg.level=lvl;
    this->msg.message=msg;
    bufffer.push_back({msg,lvl});

}

void dump(void)
{
    std::string string_of_enum=" fd";

   for(auto& i : bufffer)
   {
     for(auto & j:enum_to_string)
     {
        if(j.first==i.level)
        {
            string_of_enum=j.second;
        }
     }
      std::cout<<"\""<<i.message<<"\"      "<<string_of_enum<<std::endl;
   }
}

void clear(void)
{
  bufffer.clear();

}

};

std::vector<LOG::message> LOG::bufffer;


int main()
{

LOG log1;
log1.add_message("free(): double free detected in tcache 2 Aborted (core dumped)", LogLevel::ERROR);
log1.add_message("ISO C++ forbids converting a string constant to ‘char*’", LogLevel::WARNING);

log1.dump();

log1.clear();

log1.dump();


}