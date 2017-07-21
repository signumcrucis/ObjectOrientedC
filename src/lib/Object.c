#include "Class.h"
#include "String.h"
#include "Object.h"

string method(Object, toString)
{
    return "Object";
}

destructor(Object)
{
    /*nothing to destroy*/
}

/* the vtable */
vt_init(Object)
    vt_method(Object,toString) /*install the toString pointer*/
end

constructor(Object)
{
    clear_class_memory(Object, this);
    vt_constructor_install(Object); /*add the vtable into the object instance*/

    return this;
}