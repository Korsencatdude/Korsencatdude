
 /* This code has been written by Korsencatdude, and is a solution the the task 10.3 in the book
  * "Programming in C" by Stephen G. Kohan
  *If you by any chance want to use this code, please feel free to do so :)
  *
  * P.S this code is a work in progress, variable names and other nickpicks will be changed in the
  * future. Please contact me if you have any suggestions how i can make it better ;)
  */


#include <stdio.h>
struct week
{
    float dayOfWeek;
    struct week *tomorrow;
    
};

//function inserts a struct between the previous day and the next day
void insert_day(struct week *middleDay, struct week *previousDay)
{
   
    middleDay -> tomorrow = previousDay -> tomorrow;
    previousDay -> tomorrow = middleDay;
    
    
    
    
    
}

int main(void)
{
    
    
    struct week header;             //declearing a linked list of type week, with header as a start
    struct week monday;
    struct week tuesday;
    struct week wednesday;
    struct week madeUpDay;
    struct week *entryPtr;
    
    
    monday.dayOfWeek = 1;
    tuesday.dayOfWeek = 2;
    wednesday.dayOfWeek = 3;
    madeUpDay.dayOfWeek = 2.5;
    
    header.tomorrow = &monday;          //header points to the first struct at any given moment
    entryPtr = header.tomorrow;
    monday.tomorrow = &tuesday;
    tuesday.tomorrow = &wednesday;
    wednesday.tomorrow = (struct week *) '0'; //end of linked list
    
    insert_day(&madeUpDay, &header);
    entryPtr = header.tomorrow;
    
    
    
    while (entryPtr != (struct week *) '0')
    {
        printf("%.2f \n", entryPtr -> dayOfWeek);
        entryPtr = entryPtr ->tomorrow;
    }
    return 0;
}
