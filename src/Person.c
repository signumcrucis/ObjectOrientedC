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


#include "lib/String.h"

#include "lib/Class.h"

#include "lib/Object.h"

#include "Person.h"


getter( Person, string, name ){
    return this->name;
}
getter( Person, int, age ){
    return this->age;
}
setter(Person, string, name){
    string_set(this->name, value);
}

string method(Person, toString)
{
    return this->name;
}
destructor(Person)
{
    string_delete(this->name);
    finalize(&(this->base));
}
vt_init(Person)
    vt_getter(Person, name)
    vt_getter(Person, age)
    vt_setter(Person, name)

    vt_method(Person,toString)
end

constructor( Person,   string name )
{
    clear_class_memory(Object, this);
    initalize(Object, &(this->base));
    this->name = string_new(name);
    vt_constructor_install(Person);
    return this;
} 
constructor_overloaded(Person, si,   string name, int age)
{
    this = Person_construct ( this, name);
    this->age = age;
    return this;
} 

