#ifndef GUARD_CLASS_OBJECT
#define GUARD_CLASS_OBJECT
/* Object Class */


#include "Class.h"
#include "String.h"

class(Object);
properties(Object);
methods(Object);
    string ptr_method(Object, toString);
end;

constructor(Object);

#endif