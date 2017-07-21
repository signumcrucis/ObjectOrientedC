
#ifndef GUARD_CLASS_OBJECT
#define GUARD_CLASS_OBJECT
/* Array Class */


#include "Class.h"
#include "String.h"
#include "Object.h"

class(Array);
properties(Array);
   // Object base;
    void * ptr;
    int length;
methods(Array);
    //string ptr_method(Array, toString);
    
end;

constructor(Array, int numItems, int sizeOfType);

#endif