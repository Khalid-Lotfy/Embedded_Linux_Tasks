
#include <iostream>




class drawable 
{
    
public:

virtual void  draw()=0;
 

};


class circle :public drawable 
{
public:
  void  draw()
 {
     std::cout<<"draw a circle"<<std::endl;
 }


  
};

class rectangle :public drawable 
{
public:
  void  draw()
 {
    std::cout<<"draw a rectangle"<<std::endl;

 }

  
};

class triangle :public drawable 
{
public:
  void  draw()
 {
        std::cout<<"draw a triangle"<<std::endl;
 }


  
};

void draw_fn( drawable * ptr  )
{
   ptr->draw();
}
int main ()
{


drawable *shape;

circle circle1;
rectangle rectangle1;
triangle triangle1;

draw_fn(&circle1);
draw_fn(&rectangle1);
draw_fn(&triangle1);







}