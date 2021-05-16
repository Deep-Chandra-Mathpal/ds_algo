#include<iostream>
#include<conio.h>
int no[5],MAXSIZE=5,ft=-1,rr=-1;
int EXIT=0;
int main()
{
	int choice;
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
        if (((rr==MAXSIZE-1)&&(ft==0))||(rr==ft-1))
          std::cout<<"queue overflow\n";
        else
         {
          if (ft==-1)
            ft=0;
          rr+=1;
          rr%=MAXSIZE;
          std::cout<<"enter the no. to add : ";
          std::cin>>no[rr];
         }
	}
	int pop()
	{
	    if (ft==-1)
	      std::cout<<"queue underflow\n";
	    else
          {
           std::cout<<no[ft]<<" poped out"<<std::endl;
           if (ft==rr)
            ft=rr=-1;
           else
            {
                ft+=1;
	            ft%=MAXSIZE;
            }
          }
     return 0;
	}

	void display()
	{   if (ft==-1)
	      std::cout<<"queue is empty\n";
        else if(rr>ft)
         {
           for(int i=ft;i!=rr+1;i++)
	      {
	          std::cout<<i+1<<" : "<<no[i]<<"\n";
          }
         }
        else if(ft==rr)
         {
            std::cout<<ft+1<<" : "<<no[ft]<<std::endl;
         }
        else
            {
                for(int i=0;i<=rr;i++)
                    std::cout<<i+1<<" : "<<no[i]<<std::endl;
                for(int i=ft;i<MAXSIZE;i++)
                    std::cout<<i+1<<" : "<<no[i]<<std::endl;
            }
    }
