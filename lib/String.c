#include "String.h"
#include <stdlib.h>

void string_set(string this, string value)
{
    string_delete(this);
    this = string_new(value);
}

int string_length(string this)
{
    return strlen(this);
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