/**
 * C program to create a Singly Linked List with atleast 7 nodes and create a  replica of it in reverse order
 */

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int number;   // information part
	struct node *next;  // Address part
}node;

/* Function to reverse the linked list */
void reverseList(node *n)
{   
	node *prev=NULL, *current=NULL;
    prev = n;
    current = n-> next;
    n= n-> next;
    
    prev->next = NULL;
    while (n != NULL)
	{
        // Store next
        n = n->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = n;
    }
    n = prev;
    
    printf("The linked list  in reverse order is:-\n");
    node *temp;
     temp = n;
         while(temp != NULL)
        {
            printf("Data = %d\n", temp->number); // Print the data of current node
            temp = temp->next;                 // Move to next node
        }
        
}


int main(void)
{
	int p,i;
	
	printf("Enter the required number of nodes to be created(must be greater than or equal to 7):-\n ");
    scanf("%d", &p);
    
    
    if(p < 7)
    {
        printf("List size must be greater than 7.\n");
        return 0;
    }
    
    else
    {
    	int num;
		printf("Enter the data of node 1: ");
		scanf("%d", &num);
	
		
		node *n = (node *)malloc(sizeof(node));

		if(!n)
		{
			printf("Unable to allocate memory.");		
		}


		n-> number =num;
		n-> next = NULL;
    	
    	node *temp = n;
    	
    	for(i=2; i <= p; i++)
        {
            node *newNode = malloc(sizeof(node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
            	int data;
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->number = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }
        
        printf("The data of the linked list are:-\n");
        temp = n;
         while(temp != NULL)
        {
            printf("Data = %d\n", temp->number); // Print the data of current node
            temp = temp->next;                 // Move to next node
        }
        
        reverseList(n);

	}
    
}

