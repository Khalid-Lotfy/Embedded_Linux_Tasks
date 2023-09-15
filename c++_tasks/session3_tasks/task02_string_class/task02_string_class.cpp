#include<iostream>
#include <string>

class string
{

public:
std:: string new_string;

string():new_string("")
{

};
string(std::string str):new_string(str)
{

}

void clear(void);
unsigned int length(void);
std::string append (std::string new_part);
char front(void);
char back(void);
void insert(int position,std::string new_part);
int find(char element);


};

// clear the string
void string::clear(void)
{
  this->new_string="";
}

// return string length
unsigned int string::length()
{
    int size=0;
    for (char i:this->new_string) 
    {
       size++;
    }
    return size;
}

//add a string at the end of our string
std::string string::append (std::string new_part)
{

this->new_string =this->new_string+new_part;
return this->new_string;

}

// return first char in the string 
char string::front (void)
{
    
    return this->new_string[0];
}

// return last char in the string 
char string::back (void)
{
   int size=this->length();
   return this->new_string[size-1];
}

// insert new part in a specified position
void string::insert(int position,std::string new_part)
{
   int size=this->length();
   std::string first="";
   std::string last="";
   
   for(int i=0;i<position;++i)
   {
     first+=this->new_string[i];

   }
  
   for(int i=position;i<size;++i)
   {
     last+=this->new_string[i];
   
   }
    
   this->new_string=first+new_part+last;
   

}

// find a specified element in the string and return -1 if not found
 int string::find(char element)
{

    for (int i=0; i<this->length(); ++i)
    {
       if(this->new_string[i]==element)
       {
        return i;
       }
    }

    return (-1) ;
}



int main()
{

string str("hello world");

str.insert(5, " hello");
std::cout<<str.new_string<<std::endl;

str.append(" world");
std::cout<<str.new_string<<std::endl;

int position=str.find('e');
std::cout<<position<<std::endl;

std::cout<<"first char is:    "<<str.front()<<std::endl;

std::cout<<"last char is:     "<<str.back()<<std::endl;

std::cout<<"string length is: "<<str.length()<<std::endl;


}