#include <iostream>



int main ()
{

int arr []={15,10,6,-1,4,0};
int size=sizeof(arr)/sizeof(arr[0]);

int num,flag=0;
std::cout<<"enter numbet to delete : ";
std::cin>>num;


for(int i=0;i<size;++i)
{
  if(arr[i]==num)
  {
   
     for(int j=i;j<size;++j)
     {
        arr[j]=arr[j+1];
     }
     size--;
     flag=1;
     std::cout<<"number deleted"<<std::endl;
     break;

  }
 
}

for(int i=0;i<size;++i)
{
 std::cout<<arr[i]<<"  "<<std::endl; 
}

 if(flag==0)
  {
    std::cout<<std::endl<<"number not found"<<std::endl;

  }
 

}
