#include <iostream>
#include <conio.h>
#include <cstring>
int MAXSIZE = 8;
struct node* top = NULL;
int EXIT=0;
struct node
{
	std::string name;
	int id;
	struct node* next = NULL;
};
int main()
{
	int choice;
	char ch;
	void push();
	int pop();
	int display();
	do {
		std::cout << "enter your choice between 1 to 4 \n";
		std::cout << "1:push  2:pop  3:display  4:exit ::";
		std::cin >> choice;
		switch (choice)
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
			std::cout << "you entered wrong input\n";
		}
		
		std::cout<<std::endl;
	} while (!EXIT);
	return 0;
}
void push()
{
	struct node* n;
	n = new node;
	std::cout << "enter the name : ";
	std::cin >> n->name;
	std::cout << "enter the id : ";
	std::cin >> n->id;
	n->next = top;
	top = n;
}
int pop()
{
	if (top == NULL)
		std::cout << "stack underflow\n";
	else
	{
		std::cout << top->name;
		std::cout << " : ";
		std::cout << top->id;
		std::cout << "  poped out";
		std::cout << std::endl;
		top = top->next;
	}

	return 0;
}
int display()
{
   node *temp=top;
   if (temp==NULL)
   {
       std::cout<<"stack is empty";
       std::cout<<std::endl;
   }
   else
   {
       while(temp!=NULL)
    {
       std::cout<<temp->name<<" : "<<temp->id;
       std::cout<<std::endl;
       temp=temp->next;
    }
   }
return 0;
}

