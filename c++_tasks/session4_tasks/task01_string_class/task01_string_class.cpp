#include <cstddef>
#include <cstring>
#include<iostream>
#include <string>

class string
{

public:
 char * new_string;
unsigned int str_size;

string():new_string(nullptr),str_size(0)
{

};

string( const char * str)
{
    str_size=strlen(str);
    new_string=new char[str_size+1];
    strcpy(new_string, str);
}


~string()
{
    if(this->new_string)
    {
        delete [] this->new_string;
        this->new_string=nullptr;
    }
}

 string(const string & other)
 {
    this->str_size=other.str_size;
     new_string=new char[str_size+1];
     strcpy(this->new_string, other.new_string);
 }

 string & operator=(const string & other)
 {
    if(this!=&other)
    {
        if(this->new_string)
        {
            delete []this->new_string;
           this->new_string=nullptr;
        }
     this->str_size=other.str_size;
     this->new_string=new char[str_size+1];
     strcpy(this->new_string, other.new_string);
    }
     return *this;

 }

string( string && other)
 {
    if(other.new_string)
    {
     this->str_size=other.str_size;
     new_string=new char[str_size+1];
     strcpy(this->new_string, other.new_string);
     other.new_string=nullptr;
     other.str_size=0;
    }
 }

string & operator=( string && other)
 {
    if(this!=&other)
    {
        if(this->new_string)
        {
            delete []this->new_string;
            this->new_string=nullptr;
        }
     this->str_size=other.str_size;
     this->new_string=new char[str_size+1];
     strcpy(this->new_string, other.new_string);
     other.new_string=nullptr;
     other.str_size=0;
    }
     return *this;

 }
  
string operator+(const string & other)
{
    string result;
    
    result.str_size=this->str_size+other.str_size;
    result.new_string=new char[result.str_size+1];
    strcpy(result.new_string,this->new_string);
    strcat(result.new_string, other.new_string);
    return result;
}

void clear(void);
unsigned int length(void);
string append (const char * new_part);
char front(void);
char back(void);
void insert(int position,const char *new_part);
int find(char element);


};

// clear the string
void string::clear(void)
{
  this->new_string=nullptr;
  this->str_size=0;
}

// return string length
unsigned int string::length()
{
    return this->str_size;
}

//add a string at the end of our string
string string::append (const char * new_part)
{
this->str_size+=strlen(new_part);
char * str=new char[this->str_size+1];
strcpy(str, this->new_string);
strcat(str, new_part);
this->new_string=str;
return *this;

}

// return first char in the string 
char string::front (void)
{
    
    return this->new_string[0];
}

// return last char in the string 
char string::back (void)
{
   return this->new_string[str_size-1];
}

// insert new part in a specified position
void string::insert(int position,const char*  new_part)
{
   string result;
   result.str_size=this->str_size+strlen(new_part);
   result.new_string=new char[result.str_size+1];
  
 strcpy(result.new_string, this->new_string);
 strcpy(result.new_string+position, new_part);
 strcpy(result.new_string+position+strlen(new_part), this->new_string+position);
  

    this->str_size=result.str_size;
    this->new_string=new char[result.str_size+1];
    strcpy(this->new_string ,result.new_string);
   
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
string str2(str);
std::cout<<"str2: "<<str2.new_string<<std::endl;

string str3(std::move(str2));
std::cout<<"str3: "<<str3.new_string<<std::endl;

str3="name kh";
string str4;
string str5;

str4=str3;
std::cout<<"str4: "<<str4.new_string<<std::endl;

str5=std::move(str4);
std::cout<<"str5: "<<str5.new_string<<std::endl;

str5=str+str3;
std::cout<<"str5 after sum:  "<<str5.new_string<<std::endl;

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