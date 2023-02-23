#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int stackTop = -1;

bool stackEmpty(int stack[]){
    if (stackTop == -1){
        return true;
    } else{
        return false;
    }
}

bool overflow(int stackSize){
    if ((stackSize -1) == stackTop){
        return true;
    } else {
        return false;
    }
}

void push(int stack[], int newItem, int length){
    if (overflow(length) == false){
        stackTop++;
        stack[stackTop] = newItem;  
    } else{
        printf("ERROR: overflow\n");
    }
}

int pop(int stack[]){
    if (stackEmpty(stack)){
        return -1;
    } else{
        stackTop = stackTop -1;
        return stack[stackTop + 1];
    }    
}

void printArr(int stack[]){
    for (int i = 0; i <= stackTop; i++)
    {
        printf("%d: %d\n", i, stack[i]);
    } 
}

int main()
{
    int stack[5];
    int length = sizeof(stack)/sizeof(int);

    push(stack, 1, length);
    push(stack, 2, length);
    push(stack, 3, length);
    push(stack, 4, length);
    push(stack, 5, length);

    printArr(stack);

    int itemPopped = pop(stack); 
    itemPopped = pop(stack); 
    itemPopped = pop(stack); 
    itemPopped = pop(stack); 

    if (itemPopped == -1){
        printf("Error: underflow\n");
    } else{
        printf("Item popped was %d\n", itemPopped);
    }
    printArr(stack);



    return 0;
}