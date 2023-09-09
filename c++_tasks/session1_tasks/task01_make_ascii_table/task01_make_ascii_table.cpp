#include <iostream>
#include <string>


int main()
{
  

std::cout<<"ASCII code table"<<std::endl;
std::cout<<"+----------------------+------------------------------+"<<std::endl;
std::cout<<"|         ASCII        |           char               +"<<std::endl;
std::cout<<"+----------------------+------------------------------+"<<std::endl;

//array of the unprintaple charactares to print them as strings
std::string unprintable_chars[33]={
"NUL (null)","SOH (start of heading)","STX (start of text)",
"ETX (end of text)","EOT (end of transmission) ","ENQ (enquiry)","ACK (acknowledge)" ,"BEL (bell)" ,
"BS  (backspace) ","TAB (horizontal tab) ","LF  (NL line feed, new line)","VT  (vertical tab) " ,
"FF  (NP form feed, new page)","CR  (carriage return)","SO  (shift out) ","SI  (shift in) ",
"DLE (data link escape)","DC1 (device control 1) ","DC2 (device control 2)","DC3 (device control 3) ",
"DC4 (device control 4) ","NAK (negative acknowledge)","SYN (synchronous idle) ","ETB (end of trans. block)",
"CAN (cancel)","EM  (end of medium) ","SUB (substitute)","ESC (escape)","FS  (file separator)",
"GS  (group separator)","SPACE","RS  (record separator)" ,"US  (unit separator)"};

//print the array
for(int i=0;i<=31;++i)
 {
    std::cout<<"|   "<<i<<"                  |            "<<unprintable_chars[i]<<"                        "<<std::endl;

 }

 //print the rest of the printable charachters
 for(int i=33;i<=126;++i)
 {
    std::cout<<"|   "<<i<<"                  |            "<<static_cast<char>(i)<<"                 |"<<std::endl;
 }

 // print the last one 'del'
    std::cout<<"|   "<<127<<"                  |          "<<"DEL"<<"                 |"<<std::endl;


}


