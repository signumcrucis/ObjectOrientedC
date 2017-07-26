/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib/Class.h"
#include "lib/Object.h"
#include "lib/String.h"
#include "Person.h"



int main (int argc, char *argv[])
{

    
    /* Stack : initalize/finalize*/
    Person p1;
    initalize(Person, &p1, "bob");
    printf("p1 name: %s\n", get(&p1,name));
    finalize( &p1 );

    

    /* Heap: new/delete*/
    Person * p2 = new(Person, "joe");
    printf("p2 name: %s\n", get(p2,name));
    delete( p2 );

    /* heap with overload*/
    Person * p3 = new_overloaded(Person, si, "sam", 15);
    printf("p3 name: %s\n", get(p3,name));
    printf("p3 age: %i\n", get(p3,age));
    delete(p3);


    Object * o = new(Object);
    printf("Object %s\n", o->_m->toString(o));
    printf("Object %s\n", to_string(o));
    printf("Object %s\n", mcall(o, toString));
    delete( o );
    
    
    return 0;
}