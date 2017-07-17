
#ifndef GUARD_CLASS
#define GUARD_CLASS
#include "String.h"



//#define class_alloc(CLASS) ( CLASS * ) calloc(1, sizeof( CLASS ))
#define new_noargs(CLASS) CLASS##_construct( (( CLASS * ) calloc(1, sizeof( CLASS ))) )
#define new(CLASS,...) CLASS##_construct( (( CLASS * ) calloc(1, sizeof( CLASS ))) , __VA_ARGS__ )
#define new_overloaded(CLASS,OVERLOADNAME,...) CLASS##_construct_##OVERLOADNAME ( (( CLASS * ) calloc(1, sizeof( CLASS ))) , __VA_ARGS__ )

#define initalize(CLASS,...) CLASS##_construct( __VA_ARGS__)
#define initalize_overloaded(CLASS,OVERLOADNAME,...) CLASS##_construct_##OVERLOADNAME ( __VA_ARGS__ )

#define delete(CLASS,THIS) CLASS##_destruct( THIS ); free( THIS )
#define finalize(CLASS,THIS) CLASS##_destruct( THIS )

// Define a class based on a struct called Class_[NAME]
#define class(CLASS) typedef struct Class_##CLASS CLASS

// to call a getter function
#define get(INST,PROP) ( INST )->m->get_##PROP ( INST )

// to generate an easy getter function
#define getter(TYPE,CLASS,PROP) TYPE CLASS##_get_##PROP ( CLASS * this) //{return this-> PROP ;}

// to be loaded into the global instance of the methods struct
#define vt_getter(CLASS,PROP) .get_##PROP = & CLASS##_get_##PROP ,

// To me installed in the struct of the methods
#define ptr_getter(TYPE,CLASS,PROP) TYPE (*get_##PROP ) ( CLASS *);


// to call a setter function
#define set(INST,PROP,VAL) ( INST )->m->set_##PROP ( INST , VAL )

// to generate an easy setter function
#define setter(TYPE,CLASS,PROP) void CLASS##_set_##PROP ( CLASS * this, TYPE value) //{ this-> PROP = value ;}

// to be loaded into the global instance of the methods struct
#define vt_setter(CLASS,PROP) .set_##PROP = & CLASS##_set_##PROP ,

// To be installed in the struct of the methods
#define ptr_setter(TYPE,CLASS,PROP) void (*set_##PROP ) ( CLASS * , TYPE );

#define to_string(OBJECTPTR) ( ( OBJECTPTR )->m->toString( OBJECTPTR ) )


// Object Class
class(Object);

struct Methods_Object{
    string (*toString) (Object *);
};

struct Class_Object{
    struct Methods_Object * m;
};

Object * Object_construct(Object * this);
//string Object_toString(Object * this);
void Object_destruct(Object * this);
//END Object Class

#endif