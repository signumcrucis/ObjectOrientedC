#include "lib/String.h"
#include "lib/Class.h"

//typedef struct Class_Person Person;
class(Person);
struct Methods_Person
{
    string (*toString) (Person *);

    ptr_getter(string, Person, name);
    
    ptr_getter(int, Person, age);

    ptr_setter(string, Person, name);
    
};

struct Class_Person
{
    Object base;
    struct Methods_Person * m;
    string name;
    int age;
    //string (*getName) (Person *);
};


Person * Person_construct (Person * this, string name);
Person * Person_construct_si (Person * this, string name, int age);
void Person_destruct (Person * this);
//constructor(Person) (Person * this, char * name);