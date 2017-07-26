/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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