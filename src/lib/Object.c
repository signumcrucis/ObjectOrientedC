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