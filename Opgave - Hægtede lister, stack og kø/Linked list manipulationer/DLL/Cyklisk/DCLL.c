#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert_node(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        struct node *last_node = (*head)->prev;
        last_node->next = new_node;
        new_node->prev = last_node;
        new_node->next = *head;
        (*head)->prev = new_node;
    }
}

struct node* Search(struct node *node, int searchAfter){
    struct node *temp = node;
    do {
        if (temp->data == searchAfter)
        {
            return temp;
        }
        temp = temp->next;
    } while (temp != node);

    return NULL;
}

void deleteByIndex(struct node **headRef, int index){
    if (*headRef == NULL){
        return;
    }

    struct node *temp = *headRef;

    if (index == 0){
        *headRef = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < index-1; i++){
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}


void print_list(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct node *temp = head;
        do {
            printf("num %d current:%p perv:%p nextInLine:%p\n", temp->data, temp, temp->prev, temp->next);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    struct node *head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 10);
    insert_node(&head, 33);
    insert_node(&head, 11);
    insert_node(&head, 3);
    print_list(head);

    //deleteByIndex(&head, 2);
    //print_list(head);

    //struct node *seachedItem = Search(head, 3);
    //if (seachedItem != NULL){
    //    printf("%d\n", seachedItem->data);
    //} else{
    //    printf("Item not found\n");
    //}



    return 0;
}