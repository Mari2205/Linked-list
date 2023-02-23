#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
        (*head)->next = *head;
    } else {
        struct node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head;
    }
}

void print_list(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct node *temp = head;
        do {
            printf("num %d current:%p nextInLine:%p\n", temp->data, temp, temp->next);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    struct node *head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    print_list(head);
    return 0;
}