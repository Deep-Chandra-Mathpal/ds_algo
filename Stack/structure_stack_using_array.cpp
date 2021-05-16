#include <iostream>
#include <conio.h>
#include <cstring>
int MAXSIZE=8,top=-1;
int EXIT=0;
struct node
{
	std::string name;
    int id;
};
struct node nodeobj[8];
int main()
{
	int choice;
	char ch;
	void push();
	int pop();
	void display();
	do{
      std::cout<<"enter your choice between 1 to 4 \n";
	  std::cout<<"1:push  2:pop  3:display  4:exit ::";
	  std::cin>>choice;
     switch(choice)
	   {
	     case 1:
           push();
           break;
	     case 2:
	       pop();
	       break;
	     case 3:
           display();
	       break;
	     case 4:
	       EXIT=1;
	       break;
	     default:
	       std::cout<<"you entered wrong input\n";
	  }
	std::cout<<std::endl;
	}while(!EXIT);
return 0;
}
	void push()
	{
        if (top==MAXSIZE-1)
          std::cout<<"stack overflow\n";
        else
         {
          top+=1;
          std::cout<<"enter the name : ";
          std::cin>>nodeobj[top].name;
          std::cout<<"number to add : ";
          std::cin>>nodeobj[top].id;    }
	}
	int pop()
	{
	    if (top==-1)
	      std::cout<<"stack underflow\n";
	    else
          {
           std::cout<<nodeobj[top].name<<" : "<<nodeobj[top].id;
           std::cout<<" this node is poped out";
           std::cout<<std::endl;
	       top-=1;
          }

        return 0;
	}

	void display()
	{   if (top==-1)
	      std::cout<<"stack is empty\n";
        else
         {for(int i=0;i<=top;i++)
	      {std::cout<<i+1<<" : "<<nodeobj[i].name<<":"<<nodeobj[i].id<<"\n";}}
	}
