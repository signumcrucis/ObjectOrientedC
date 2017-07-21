
#include "lib/String.h"

#include "lib/Class.h"

#include "lib/Object.h"

#include "Person.h"


getter( Person, string, name ){
    return this->name;
}
getter( Person, int, age ){
    return this->age;
}
setter(Person, string, name){
    string_set(this->name, value);
}

string method(Person, toString)
{
    return this->name;
}
destructor(Person)
{
    string_delete(this->name);
    finalize(&(this->base));
}
vt_init(Person)
    vt_getter(Person, name)
    vt_getter(Person, age)
    vt_setter(Person, name)

    vt_method(Person,toString)
end

constructor( Person,   string name )
{
    clear_class_memory(Object, this);
    initalize(Object, &(this->base));
    this->name = string_new(name);
    vt_constructor_install(Person);
    return this;
} 
constructor_overloaded(Person, si,   string name, int age)
{
    this = Person_construct ( this, name);
    this->age = age;
    return this;
} 

