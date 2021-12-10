// C program to search an item in binary tree

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* left;
    struct node* right;

} Node;

void AddNode(Node** root, int item)
{
    Node* temp = *root;
    Node* prev = *root;

    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));

        (*root)->item = item;
        (*root)->left = (*root)->right = NULL;
    }
    else {
        while (temp != NULL) {
            if (item > temp->item) {
                prev = temp;
                temp = temp->right;
            }
            else {
                prev = temp;
                temp = temp->left;
            }
        }
        temp = (Node*)malloc(sizeof(Node));
        temp->item = item;

        if (item >= prev->item)
            prev->right = temp;
        else
            prev->left = temp;
    }
}

void DFS(Node* root)
{
    if (root) {
        if (root->left)
            DFS(root->left);

        if (root->right)
            DFS(root->right);

        printf("%d  ", root->item);
    }
}

int search(Node* root, int item)
{
    while (root != NULL) {
        if (item > root->item)
            root = root->right;
        else if (item < root->item)
            root = root->left;
        else
            return 1;
    }
    return 0;
}

int main()
{

    struct node* head = NULL;

    AddNode(&head, 10);
    AddNode(&head, 20);
    AddNode(&head, 40);
    AddNode(&head, 30);
    AddNode(&head, 60);

    printf("Tree Items:\n");
    DFS(head);
    printf("\n");

    if (search(head, 70))
        printf("%d item found in tree.\n", 70);
    else
        printf("%d item not found in tree.\n", 70);

    if (search(head, 40))
        printf("%d item found in tree.\n", 40);
    else
        printf("%d item not found in tree.\n", 40);

    return 0;
}
