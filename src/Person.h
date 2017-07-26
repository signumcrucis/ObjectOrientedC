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

#ifndef GUARD_CLASS_PERSON
#define GUARD_CLASS_PERSON
#include "lib/String.h"
#include "lib/Class.h"
#include "lib/Object.h"

class(Person);
properties(Person);
    Object base;
    string name;
    int age;
methods(Person);
    ptr_getter( Person,string, name);
    
    ptr_getter(Person, int, age);

    ptr_setter(Person, string, name);

    string ptr_method(Person, toString);
end;



constructor( Person,   string name );
constructor_overloaded(Person, si,   string name, int age);
//Person * Person_construct_si (Person * this, string name, int age);
//void Person_destruct (Person * this);
#endif