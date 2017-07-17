#ifndef GUARD_STRING
#define GUARD_STRING

#include <string.h>

typedef char * string;


void string_set(string this, string value);

int string_length(string this);

string string_new(string value);

void string_delete(string this);

#endif