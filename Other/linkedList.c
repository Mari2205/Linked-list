#include <stdio.h>
#include <stdlib.h>

struct pPerson
{
    int age;
    struct pPerson *nextInLine;
};

struct pPerson *getNewPerson(const int age)
{
    struct pPerson *newPerson = NULL;
    newPerson = malloc(sizeof(struct pPerson));
    newPerson->nextInLine = NULL;
    newPerson -> age = age;
    printf("Created new person at %p\n", newPerson);

    return newPerson;
    
};

void printPerson(const struct pPerson *person, const char *commert){
    if (person == NULL)
    {
        printf("%s is NULL\n", commert);
    }
    else
    {
        printf("%s: age:%d address:%p nextInLine:%p\n", commert, 
        person-> age, 
        person,
        person-> nextInLine);
    }
}

int main()
{
    printf("Hallo\n");

    struct pPerson *first = NULL;
    struct pPerson *second = NULL;

    printPerson(first, "first");
    printPerson(second, "second");

    first = getNewPerson(12);
    second = getNewPerson(122);

    printPerson(first, "first");
    printPerson(second, "second");

    first->nextInLine = second;

    printPerson(first, "first");
    printPerson(first->nextInLine, "first->nextInLine");
    printPerson(second, "second");

    free(first);
    free(second);

    first = NULL;
    second = NULL;

    return 0;
}