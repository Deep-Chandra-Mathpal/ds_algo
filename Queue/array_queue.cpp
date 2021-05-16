#include<iostream>
#include<conio.h>
int no[8],MAXSIZE=8,front=-1,rear=-1;
int EXIT=0;
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
          std::cout<<"enter the no. to add : ";
          std::cin>>no[rear];
         }
	}
	int pop()
	{
	    if (front==-1||front>rear)
	      std::cout<<"queue underflow\n";
	    else
          {
           std::cout<<no[front]<<" poped out"<<std::endl;
	       front+=1;
          }
     return 0;
	}

	void display()
	{   if (front==-1||front>rear)
	      std::cout<<"queue is empty\n";
        else
         {for(int i=front;i<=rear;i++)
	      {std::cout<<i+1<<" : "<<no[i]<<"\n";}}
	}
