#include "Array.h"
#include <stdlib.h>
constructor(Array, int numItems, int sizeOfType){
    clear_class_memory(Array, this);
    //initalize(Object, &(this->base));
    this->ptr = new_array(numItems, sizeOfType);

}
destructor(Array){
    free(this->ptr);

}