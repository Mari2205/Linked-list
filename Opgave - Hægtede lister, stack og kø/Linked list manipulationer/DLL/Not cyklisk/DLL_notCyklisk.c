#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *nextInLine;
    struct Node *prev;
};

void pushInFront(struct Node **headRef, int NewNum){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode-> num = NewNum;
    newNode-> nextInLine = (*headRef);
    newNode-> prev = NULL;

    if ((*headRef != NULL)){
        (*headRef)->prev = newNode;
    }
    
    (*headRef) = newNode;
    
}

void append(struct Node **headRef, int newNum){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *headRef;

    newNode->num = newNum;
    newNode->nextInLine = NULL;

    if (*headRef == NULL)
    {
        newNode->prev = NULL;
        *headRef = newNode;
        return;
    }

    while (last->nextInLine != NULL)
    {
        last = last->nextInLine;
    }

    last->nextInLine = newNode;
    newNode->prev = last;

    return;
}

void printLst(struct Node *node){
    struct Node *last;

    printf("\nNormal: \n");
    while (node != NULL)
    {
        printf("num %d current:%p prev:%p nextInLine:%p\n", node->num, 
        node, 
        node->prev,
        node->nextInLine);

        last = node;
        node = node->nextInLine;
    }

    printf("\nReverse: \n");
    while (last != NULL) {
        printf("num %d current:%p prev:%p nextInLine:%p\n", last->num, 
        last, 
        last->prev,
        last->nextInLine);

        last = last->prev;
    }
    
}

struct Node* Search(struct Node *node, int searchAfter){
    while (node != NULL)
    {
        if (node->num == searchAfter)
        {
            return node;
        }
        node = node->nextInLine;
    }
    return node;
}

void deleteByIndex(struct Node **headRef, int index){
    if (*headRef == NULL){
        return;
    }

    struct Node *temp = *headRef;

    if (index == 0){
        *headRef = temp->nextInLine;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index-1; i++){
        temp = temp->nextInLine;
    }

    if (temp == NULL || temp->nextInLine == NULL)
    {
        return;
    }

    struct Node *next = temp->nextInLine->nextInLine;
    free(temp->nextInLine);
    temp->nextInLine = next;
}

int main()
{
    printf("Hallo world\n");

    struct Node *head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    pushInFront(&head, 0);
    append(&head, 5);

    printf("\nCreated doublet linked list is:\n");
    printLst(head);
    

    //deleteByIndex(&head, 3);
    
    //printf("\nCreated linked list is:\n");
    //printLst(head);

    //struct Node *d = Search(head, 55);
    //if (d != NULL){
    //    printf("%d\n", d->num);
    //} else{
    //    printf("Item not found\n");
    //}



    return 0;
}