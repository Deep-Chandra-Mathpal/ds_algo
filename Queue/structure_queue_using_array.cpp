#include <iostream>
#include <conio.h>
#include <cstring>
int MAXSIZE=8,front=-1,rear=-1;
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
        if (rear==MAXSIZE-1)
          std::cout<<"queue overflow\n";
        else
         {
          if (front==-1)
          	front=0;
          rear+=1;
          std::cout<<"enter the name : ";
          std::cin>>nodeobj[rear].name;
          std::cout<<"number to add : ";
          std::cin>>nodeobj[rear].id;    }
	}
	int pop()
	{
	    if (front==-1||front>rear)
	      std::cout<<"queue underflow\n";
	    else
          {
           std::cout<<nodeobj[front].name<<" : "<<nodeobj[front].id;
           std::cout<<" this node is poped out";
           std::cout<<std::endl;
	       front+=1;
          }

        return 0;
	}

	void display()
	{   if (front==-1||front>rear)
	      std::cout<<"queue is empty\n";
        else
         {for(int i=front;i<=rear;i++)
	      {std::cout<<i+1<<" : "<<nodeobj[i].name<<":"<<nodeobj[i].id<<"\n";}}
	}
