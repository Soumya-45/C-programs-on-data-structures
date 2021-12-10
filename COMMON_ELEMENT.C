// C program to find the first common element
// from the given linked lists

#include <stdio.h>
#include <stdlib.h>

//Self-referential structure to create the node.
typedef struct tmp {
    int item;
    struct tmp* next;
} Node;

//structure for creating the linked list.
typedef struct
    {
    Node* head;
    Node* tail;

} List;

//Initialize List
void initList(List* lp)
{
    lp->head = NULL;
    lp->tail = NULL;
}

//Create node and return the reference of it.
Node* createNode(int item)
{
    Node* nNode;

    nNode = (Node*)malloc(sizeof(Node));

    nNode->item = item;
    nNode->next = NULL;

    return nNode;
}

//Add a new item at the end of the list.
void addAtTail(List* lp, int item)
{
    Node* node;
    node = createNode(item);

    //if list is empty.
    if (lp->head == NULL) {
        lp->head = node;
        lp->tail = node;
    }
    else {
        lp->tail->next = node;
        lp->tail = lp->tail->next;
    }
}

//Add a new item at beginning of the list.
void addAtHead(List* lp, int item)
{
    Node* node;
    node = createNode(item);

    //if list is empty.
    if (lp->head == NULL) {
        lp->head = node;
        lp->tail = node;
    }
    else {
        node->next = lp->head;
        lp->head = node;
    }
}

//To print the list from start to end of the list.
void printList(List* lp)
{
    Node* node;

    if (lp->head == NULL) {
        printf("\nEmpty List");
        return;
    }

    node = lp->head;

    while (node != NULL) {
        printf("| %05d |", node->item);
        node = node->next;

        if (node != NULL)
            printf("--->");
    }
    printf("\n\n");
}

void findFirstCommon(List* lp1, List* lp2)
{
    Node* temp1;
    Node* temp2;

    int flag = 0;

    temp1 = lp1->head;

    while (temp1 != NULL) {
        temp2 = lp2->head;
        while (temp2 != NULL) {
            if (temp1->item == temp2->item) {
                printf("First Common Item is: %d\n", temp1->item);
                flag = 1;
                goto OUT;
            }
            temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }
OUT:
    if (flag == 0)
        printf("No common item found\n");
}

//Main function to execute program.
int main()
{
    List* lp1;
    List* lp2;

    lp1 = (List*)malloc(sizeof(List));
    lp2 = (List*)malloc(sizeof(List));

    initList(lp1);
    initList(lp2);

    addAtTail(lp1, 101);
    addAtTail(lp1, 102);
    addAtTail(lp1, 103);
    addAtTail(lp1, 104);
    addAtTail(lp1, 105);

    addAtTail(lp2, 201);
    addAtTail(lp2, 202);
    addAtTail(lp2, 103);
    addAtTail(lp2, 204);
    addAtTail(lp2, 205);

    printf("List1:\n");
    printList(lp1);

    printf("List2:\n");
    printList(lp2);

    findFirstCommon(lp1, lp2);

    return 0;
}
