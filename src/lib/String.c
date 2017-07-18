#include <stdlib.h>
#include "String.h"
/* Primative string */
void string_set(string this, string value)
{
    string_delete(this);
    this = string_new(value);
}
string string_new(string value)
{
    string this = calloc(strlen(value)+1, sizeof(char));
    strcpy(this, value);
    return this;
}
void string_delete(string this)
{
    free(this);
}

/*String Class
setter(String, string, value)
{
    string_set(this->value, value);
}

deconstructor(String)
{
    string_delete(this->value);
}
vt_init(String)
    vt_setter(String, value)
    vt_method(String, toString)
end
constructor(String, string value)
{
    this->value = string_new(value);
    this->length = strlen(value);
}
*/