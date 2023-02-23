#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int head = 0;
int tail = 0;
int size = 0;

void enQueue(int queue[], int newItem, int length){
    //queue[tail] = newItem;

    if (tail == (length - 1)){
        queue[tail] = newItem;
        tail = 0;
    } else if(size != (length - 1)){
        queue[tail] = newItem;
        tail++;
        size++;
    } else {
        printf("ERROR: Overflow\n");
    }
    
}

int deQueue(int queue[], int length){
    int x = queue[head];
    if (head == (length-  1)){
        head = 0;
    } else{
        head++;
        size--;
    }
    return x;
}



void printArr(int queue[], int length){
    for (int i = 0; i < length; i++)
    {
        printf("%d: %d\n", i, queue[i]);
    } 
}

void printQueue(int queue[]){
    for (int i = head; i < tail; i++ ){
        printf("H: %d, T: %d, Contents: %d\n", head, tail, queue[i]);
    }
    
}

int main()
{
    int queue[5];
    int length = sizeof(queue)/sizeof(int);

    enQueue(queue, 12, length);
    enQueue(queue, 70, length);
    enQueue(queue, 1, length);
    enQueue(queue, 3, length);
    enQueue(queue, 4, length);


    printArr(queue, length);
    printQueue(queue);

    int item1 = deQueue(queue, length);
    printf("deQueued %d\n", item1);
    int item2 = deQueue(queue, length);
    printf("deQueued %d\n", item2);
    
    //printf("test\n");
    printArr(queue, length);
    printQueue(queue);


    enQueue(queue, 664, length);
    enQueue(queue, 6634, length);
    enQueue(queue, 66333, length);
    enQueue(queue, 663333, length);

    printQueue(queue);
    printArr(queue, length);


    return 0;
}