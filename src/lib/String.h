#ifndef GUARD_STRING
#define GUARD_STRING

#include <string.h>
#include "Class.h"
/* Primative string */
typedef char * string;
void string_set(string this, string value);
string string_new(string value);
void string_delete(string this);

/*String Class

class(String);
    properties(String);
        string value;
        int length;
    methods(String);
        ptr_method(String, toString);
        ptr_setter(String, string, value);
end;*/

#endif