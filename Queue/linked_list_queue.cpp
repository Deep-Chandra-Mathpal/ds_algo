#include <iostream>
#include <conio.h>
#include <cstring>
int EXIT=0;
struct node
{
	std::string name;
    int id;
    node* next=NULL;
};
node* ft=NULL;
node* rr=NULL;
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
		  node* nodeobj;
		  nodeobj = new node;
          std::cout<<"enter the name : ";
          std::cin>>nodeobj->name;
          std::cout<<"number to add : ";
          std::cin>>nodeobj->id;
          if (ft==NULL)
          	ft=rr=nodeobj;
          else
          	{
          		rr->next=nodeobj;
                rr=nodeobj;
            }
	}
	int pop()
	{
	    if (ft==NULL)
	      std::cout<<"queue underflow\n";
	    else
          {
           std::cout<<ft->name<<" : "<<ft->id;
           std::cout<<" this node is poped out";
           std::cout<<std::endl;
	       ft=ft->next;
          }

        return 0;
	}

	void display()
	{   if (ft==NULL)
	      std::cout<<"queue is empty\n";
        else
          {
          	node* temp=ft;
          	while (temp!=NULL)
          	{
          		std::cout<<temp->name<<" : "<<temp->id;
          		temp=temp->next;
          		std::cout<<std::endl;
          	}
          }
	}
