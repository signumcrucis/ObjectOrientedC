#include <stdio.h>
#include <stdlib.h>
#include "lib/Class.h"
#include "Person.h"
#include "lib/String.h"
//#include "LinkedList.h"

//LinkedListOf(Person)

int main ()
{
    // Stack : initalize/finalize
    Person p1;
    initalize(Person, &p1, "bob");
    printf("p1 name: %s\n", get(&p1,name));
    finalize( &p1 );

    // Heap: new/delete
    Person * p2 = new(Person, "joe");
    printf("p2 name: %s\n", get(p2,name));
    delete( p2 );

    // heap with overload
    Person * p3 = new_overloaded(Person, si, "sam", 15);
    printf("p3 name: %s\n", get(p3,name));
    printf("p3 age: %i\n", get(p3,age));
    delete(p3);


    Object * o = new_noargs(Object);
    printf("Object %s\n", o->_->toString(o));
    printf("Object %s\n", to_string(o));
    printf("Object %s\n", mcall_noargs(o, toString));
    delete( o );
    

    return 0;
}