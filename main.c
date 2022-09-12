#include <stdio.h>
struct doubleList
{
    int value;
    struct doubleList *next;
    struct doubleList *previous;
};
  // insert node changes both the pointer to the
  //previous node(*previous) and the next node (*next)

void insertNode(struct doubleList *insert, struct doubleList *before)
{
    insert -> next = before -> next;
    before -> next -> previous = insert;
    before -> next = insert;
    insert -> previous = before;
 
    
}


int main(void)
{
    struct doubleList header;
    struct doubleList list1;
    struct doubleList list2;
    struct doubleList random;
    struct doubleList list3;
    struct doubleList *ptr;
    
    list1.value = 1;
    list2.value = 2;
    list3.value = 3;
    random.value = 45;
    
    

    header.next = &list1;
    ptr = header.next;
    list1.next = &list2;
    list1.previous = (struct doubleList *) '0';
    list2.next = &list3;
    list2.previous = &list1;
    list3.next = (struct doubleList *) '0';
    list3.previous = &list2;
    
    
    
    while (ptr != (struct doubleList *) '0')
    {
        printf("%i \n", ptr -> value);
        ptr = ptr -> next;
        
    }
    
    
    insertNode(&random, &list2);
    ptr = header.next;
    
    while (ptr != (struct doubleList *) '0')
    {
        printf("%i \n", ptr -> value);
        ptr = ptr -> next;
        
    }
    return 0;
}
