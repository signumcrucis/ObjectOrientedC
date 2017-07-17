#include "Person.h"
#include "lib/String.h"
#include "lib/Class.h"

//PUBLIC METHODS
// string Person_get_name(Person * this)
// {
//     return this->name;
// }

getter(string, Person, name){
    return this->name;
}
getter(int, Person, age){
    return this->age;
}
setter(string, Person, name){
    string_set(this->name, value);
}

string Person_toString(Person * this)
{
    return this->name;
}

struct Methods_Person methods_Person = { 
    vt_getter(Person, name)
    vt_getter(Person, age)
    vt_setter(Person, name)
    .toString = &Person_toString,
};

//CONSTRUCTORS
Person * Person_construct (Person * this, string name)
{
    initalize(Object, &(this->base));
    this->name = string_new(name);
    this->m = &methods_Person;
    return this;
} 
Person * Person_construct_si (Person * this, string name, int age)
{
    this = Person_construct ( this, name);
    this->age = age;
    return this;
} 
void Person_destruct (Person * this)
{

    string_delete(this->name);
    finalize(Object, &(this->base));
} 
