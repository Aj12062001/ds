#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*next;
};
struct node*top=NULL;
void pop()
{
	if(top==NULL)
        {
                printf("stack is underflow\n");
        	return;
	}
        struct node*temp=top;
	top=(top)->next;
	printf("%d popped from the stack\n",temp->data);
	free(temp);

}
void push()
{
	int value;
	struct node*newNode=(struct node*)malloc(sizeof(struct node));
	if (!newNode)
	{
		printf("stack over flow\n");
	}
	else
	{
		printf("enter the element:");
		scanf("%d",&value);
		if(top==NULL)
		{
			newNode->data=value;
			newNode->next=NULL;
			top=newNode;
		}
		else
		{
			newNode->data=value;
                        newNode->next=top;
                        top=newNode;
         	 }
		printf("%d pushed into the stack\n",value);
	}
}
void display()
{
	if(top==NULL)
	{
		printf("stack is empty\n");
        }
        else
        {
		printf("linked list using stack:");
		struct node*temp=top;
		 while(temp!=NULL)
                {
                        printf("%d \n",temp->data);
                        temp=temp->next;
                }
        }

}
void search()
{
	struct node*temp=top;
	int postion=1,found=0,el;
	if(top==NULL)
        {
                printf("stack is empty\n");
        }
        else
        {
		printf("enter the value to search:");
                       scanf("%d",&el);

		while(temp!=NULL)
                {
			if(temp->data==el)
			{
				printf("%d found at the postion %d\n",el,postion);
				found=1;
				break;
			}
			temp=temp->next;
			postion++;
		}
		if(found==0)
			printf("%d is not found in the stack",el);
	}
}
int main()
{
	int ch;
	printf("enter the funtion to execute\n");
	do
	{
		printf("\n1.push\n2.pop\n3.display\n4.search");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
		       		break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:search();
		       		break;
			default:printf("stack is invalid");
		}
	}while(ch!=5);
	return 0;
}
