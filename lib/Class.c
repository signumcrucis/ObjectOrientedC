#include "Class.h"
#include "String.h"



string Object_toString(Object * this)
{
    return "Object";
}
struct Methods_Object methods_Object = {.toString = &Object_toString};

Object * Object_construct(Object * this)
{
    this->m = &methods_Object;
    return this;
}
void Object_destruct(Object * this)
{
    
}