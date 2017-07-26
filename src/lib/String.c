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