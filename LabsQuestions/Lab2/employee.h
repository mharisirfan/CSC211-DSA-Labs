/** This file will contains the definition of one element/node (structure) of the linked list
    and the functions associated with the list.
    */

struct employee
{
   char name[50];
   int age;
   float bs;

   struct employee * next;
};

void inEmpRec(struct employee * emp);
void displayEmpRec(struct employee * emp);
void printList(struct employee * emp);
struct employee *  insertEnd(struct employee * last);
bool isEmpty(struct employee * emp);
int listLength(struct employee * emp);

