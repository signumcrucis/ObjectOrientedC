
#ifndef GUARD_CLASS
#define GUARD_CLASS


#define clear_class_memory(CLASS, POINTER) memset ( POINTER , 0, sizeof( struct Class_##CLASS ) )


#define new_array(TYPE,NUM) calloc(NUM, sizeof( TYPE ))

#define new(CLASS,PARAMS...) CLASS##_construct( (( CLASS * ) calloc(1, sizeof( CLASS ))) , ## PARAMS )
#define new_overloaded(CLASS,OVERLOADNAME,...) CLASS##_construct_##OVERLOADNAME ( (( CLASS * ) calloc(1, sizeof( CLASS ))) , __VA_ARGS__ )

#define initalize(CLASS,...) CLASS##_construct( __VA_ARGS__ )
#define initalize_overloaded(CLASS,OVERLOADNAME,...) CLASS##_construct_##OVERLOADNAME ( __VA_ARGS__ )

#define METHODSTRUCT _m

#define delete(THIS) ( THIS )->METHODSTRUCT->destruct( THIS ); free( THIS ); THIS = NULL
#define finalize(THIS) ( THIS )->METHODSTRUCT->destruct( THIS )

#define constructor(CLASS,PARAMS...) CLASS * CLASS##_construct( CLASS * this, ## PARAMS )
#define constructor_overloaded(CLASS,OVERLOADNAME,PARAMS...) CLASS * CLASS##_construct_##OVERLOADNAME ( CLASS * this, ## PARAMS )

#define destructor(CLASS) void CLASS##_destruct( CLASS * this )

/* usage: void method(Person, string name) {...}*/
#define method(CLASS,NAME,PARAMS...) CLASS##_##NAME ( CLASS * this, ## PARAMS )

#define method_overloaded(CLASS,NAME,OVERLOADNAME,PARAMS...) CLASS##_##NAME##_##OVERLOADNAME ( CLASS * this, ## PARAMS )

/* Define a class based on a struct called Class_[NAME]*/
#define class(CLASS) typedef struct Class_##CLASS CLASS;
#define properties(CLASS) struct Class_##CLASS { struct Methods_##CLASS * METHODSTRUCT;
#define methods(CLASS) }; struct Methods_##CLASS { void (*destruct) ( CLASS *);
#define end };

/* to call a getter function*/
#define get(INST,PROP) ( INST )->METHODSTRUCT->get_##PROP ( INST )

/* to generate an easy getter function*/
#define getter(CLASS,TYPE,PROP) TYPE CLASS##_get_##PROP ( CLASS * this)

/* to be loaded into the global instance of the methods struct*/
#define vt_getter(CLASS,PROP) .get_##PROP = & CLASS##_get_##PROP ,

/* To me installed in the struct of the methods*/
#define ptr_getter(CLASS,TYPE,PROP) TYPE (*get_##PROP ) ( CLASS *);


/* to call a setter function*/
#define set(INST,PROP,VAL) ( INST )->METHODSTRUCT->set_##PROP ( INST , VAL )

/* to generate an easy setter function*/
#define setter(CLASS,TYPE,PROP) void CLASS##_set_##PROP ( CLASS * this, TYPE value)

/* to be loaded into the global instance of the methods struct*/
#define vt_setter(CLASS,PROP) .set_##PROP = & CLASS##_set_##PROP ,

/* To be installed in the struct of the methods*/
#define ptr_setter(CLASS,TYPE,PROP) void (*set_##PROP ) ( CLASS * , TYPE );

#define to_string(OBJECTPTR) ( ( OBJECTPTR )->METHODSTRUCT->toString( OBJECTPTR ) )

#define mcall(OBJECTPTR, METHODNAME, PARAMS...) (( OBJECTPTR )->METHODSTRUCT-> METHODNAME ( OBJECTPTR , ## PARAMS ) )

#define mcall_overloaded(OBJECTPTR, METHODNAME,OVERLOADNAME, PARAMS...) (( OBJECTPTR )->METHODSTRUCT-> METHODNAME_##OVERLOADNAME ( OBJECTPTR , ## PARAMS ) )
/*usage:    string ptr_method(Person, toString)*/
#define ptr_method(CLASS,METHODNAME,PARAMS...) ( * METHODNAME) ( CLASS * , ## PARAMS )

#define ptr_method_overloaded(CLASS,METHODNAME,OVERLOADNAME,PARAMS...) ( * METHODNAME_##OVERLOADNAME ) ( CLASS * , ## PARAMS )

#define vt_method(CLASS,METHODNAME) .METHODNAME = & CLASS##_##METHODNAME ,
#define vt_method_overloaded(CLASS,METHODNAME,OVERLOADNAME) .METHODNAME##_##OVERLOADNAME = & CLASS##_##METHODNAME_##OVERLOADNAME ,

/* use with "end" macro */
#define vt_init(CLASS) struct Methods_##CLASS methods_##CLASS = { vt_method( CLASS ,destruct)


#define vt_constructor_install(CLASS) this->METHODSTRUCT = &methods_##CLASS





#endif