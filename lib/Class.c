#include "Class.h"
#include "String.h"



string Object_toString(Object * this)
{
    return "Object";
}

struct Methods_Object methods_Object = {
    .toString = &Object_toString,
    .destruct = &Object_destruct,
};
Object * Object_construct(Object * this)
{
    this->METHODSTRUCT = &methods_Object;
    return this;
}
void Object_destruct(Object * this)
{
    
}
