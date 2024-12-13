#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}


void insert_at_head() 
{
   int data;
    printf("enter your number: ");
    scanf("%d",&data);
    struct node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void insert_at_tail()
 {
   int data;
    printf("enter your number: ");
    scanf("%d",&data);
    struct node* new_node = create_node(data);
    if (tail == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}
void insertAtPosition(int item,int position)
{
        if(position<1)
        {
                printf("Position cannot be <1.\n");
                return;
        }
        if(position == 1)
        {
                insert_at_head(item);
                return;
        }

        struct node * newnode = create_node(item);
        struct node * temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
                temp = temp->next;
        }
        if (temp == NULL)
        {
                printf("Position Not available.\n");
                free(newnode);
        }
        else
        {
                newnode->next = temp->next;
                newnode->prev = temp;
                temp->next = newnode;
                temp->next->prev = newnode;
                printf("Item Inserted at %d position!\n",position);
        }
}


void delete_at_head() {
    if (head == NULL) {
        return;
    }
    struct node* temp = head;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}
// delete the node at the end of the list

void delete_at_tail() {
    if (tail == NULL) {
        return;
    }
    struct node* temp = tail;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}
void deleteFromPosition(int position)
{
        if (head == NULL)
        {
                printf("List is empty.\n");
                return;
        }
        if (position < 1)
        {
                printf("Position cannot be <1.\n");
                return;
        }
        if (position == 1)
        {
                delete_at_head();
                return;
        }

        struct node* temp = head;
        struct node* loc = NULL;

        for (int i = 1; i < position && temp != NULL; i++)
        {
                loc = temp;
                temp = temp->next;
        }
        if (temp == NULL)
        {
                printf("Position Not available.\n");
        }
        else
        {
                loc->next = temp->next;
                free(temp);
                printf("Item Deleted!\n");
        }
}
// display the list in forward direction

void display_forward() {
    struct node* current = head;
    if(current==NULL)
{
	printf("list is empty");
}
else{
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    } 
    printf("\n");
}
}
// main function to test the doubly linked list

int main()
 {
    struct Node* head = NULL;
          int choice=0,item,position;
        while(choice!= 8)
        {
                printf("\nEnter your choice: \n");
                printf("\n 1.Insert in begining\n 2.Insert at tail\n 3.Delete from Beginning\n 4.Delete from tail\n 5.display_forward \n 6.insert At Position\n 7.delete From Position \n 8.exit  ");
                scanf("\n%d",&choice);
                switch(choice)
                {
                        case 1:	insert_at_head();
				display_forward();
                                break;
                        case 2: insert_at_tail();
				display_forward();
                                break;
                        case 3: delete_at_head();
				display_forward();
                                break;
			case 4: delete_at_tail();
                                display_forward();
                                break;
                        case 5:display_forward();
                                break;
			case 6: printf("Enter item to be inserted :");
                                scanf("%d",&item);
                                printf("Enter the position :");
                                scanf("%d",&position);
                                insertAtPosition(item,position);
                                display_forward();
                                break;
			case 7: printf("Enter the position :");
                                scanf("%d",&position);
                                deleteFromPosition(position);
                                display_forward();
                                break;
                        case 8:exit(0);
                                break;
                        default:printf("Invalid choice!Try again.\n");
                                break;
                }
        }

	  return 0;
}
