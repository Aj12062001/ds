#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *head=NULL;
void insertAtBeginning( int data)
{

    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    if(head==NULL)
	{
	head=newnode;
	newnode->next=NULL;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}


}
void printList(struct Node* node)
{
    struct Node* temp = head;
    while (temp != NULL)
	{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


}

void insertAtEnd(int data)
{
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
	printf("\nOVERFLOW");
	}
	else
	{
	printf("\nEnter value?\n");
	scanf("%d",&item);
	ptr->data = item;
if(head == NULL)
{
ptr -> next = NULL;
head = ptr;
printf("\nNode inserted");
}
else
{
temp = head;
while (temp -> next != NULL)
{
temp = temp -> next;
}
temp->next = ptr;
ptr->next = NULL;
printf("\nNode inserted");
}
}

}
void deleteathead(struct Node** head, int key)
{
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key)
{
        *head = temp->next;
        free(temp);
        return;
    }

void deleteattail()
{
 if(head==NULL)
 return;
  if((head
}
int search(struct Node* head, int target)
{
    struct Node* current = head;
    while (current != NULL)
	{
        	if (current->data ==target)
		{
            	return 1;
        	}
        	current = current->next;
       }
    return -1;
int main()
{
        int ch,data;
	while(1)
	{
	printf("enter your choice:");
		printf("\n 1.insert at head\n 2.insert at tail\n 3.delete at head\n 4.delete at tail\n 5.print list\n 6.search an element\n 7.exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter the data to be insert at head:");
				scanf("%d",&data);
				insertAtBeginning(data);
				break;
			/*case 2:printf("enter the data to be insert at tail:");
                                scanf("%d",&data);
                                insertAtEnd(&head,data);
                                break;
			case 3:printf("enter the data to be delete at head:");
                                scanf("%d",&data);
                                deleteathead(&head,data);
                                break;
			case 4:printf("enter the data to be delete at tail:");
                                scanf("%d",&data);
                                deleteattail(&head,data);
                                break;
			case 5:printf("singly linked list:");
                                printList(head);
                                break;
			case 6:printf("enter the data to search:");
                                scanf("%d",&data);
                                search(&head,data);
				if(return!=-1) 
				{
        				printf("target %d found in the list %d.\n",target,result);
  				 }
				else 
				{
        				printf("%d not found in the list.\n",target);
    				}

                                break;*/
			case 5:printf("singly linked list:");
                                printList(head);
                                break;

			case 7:exit(0);
			default:printf("there is an error in the singly linked list");
	   	}
	}
	return 0;
}
