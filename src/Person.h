#ifndef GUARD_CLASS_PERSON
#define GUARD_CLASS_PERSON
#include "lib/String.h"
#include "lib/Class.h"
#include "lib/Object.h"

class(Person);
properties(Person);
    Object base;
    string name;
    int age;
methods(Person);
    ptr_getter( Person,string, name);
    
    ptr_getter(Person, int, age);

    ptr_setter(Person, string, name);

    string ptr_method(Person, toString);
end;



constructor( Person,   string name );
constructor_overloaded(Person, si,   string name, int age);
//Person * Person_construct_si (Person * this, string name, int age);
//void Person_destruct (Person * this);
#endif