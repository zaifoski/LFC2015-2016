/**
	this file will contain generally useful function such as
	those that manage the environment
	EG put and get symbol from the symbol table
	as well as structures and so on..
*/
#ifndef HEADER_H
#define	HEADER_H



/* FUNCTION TYPE*/
typedef double (*funct_t)(double);


enum data_type {dt_integer, dt_float, dt_array, dt_structure} ;
enum LR_type {type_VAR, type_NUM, type_STRUCT};
/*DATA TYPE FOR LINKS IN THE CHAIN OF SYMBOLS*/

typedef struct basicType{
	enum data_type datatype; //coerenza tra basic, array e type
	union{
		int i;
		float f;
	} value;
} basic;
typedef struct arrayType
{
	enum data_type datatype;
	int size;
	union{
		basic **b;
		struct arrayType **a;
	} value;
} array;

typedef struct type{
	enum data_type datatype; //is coming from the basic type or either the array or the struct etc etc
	union{
		basic *b;
		array *a;
		struct record *r;
	} value;
}type;

typedef struct ref{
	int n; // the actual position
	struct ref * next; // next position
}ref;

typedef struct symrec
{
	char * name; //name of the symbol-variable
	type * tipo;
	ref * ref; //ref to be cleaned after each assignment - holds current accessed position
	struct symrec *next;
} symrec;

typedef struct record{
	struct symrec * tabella;
}record;

typedef struct LRhand{
    enum LR_type type; //è il tipo di valore che stiamo andando a valutare - serve per lo "switch" sulle "funzioni di valutazione"
    union{
        symrec * rec; // il record che dobbiamo valutare/assegnare
        double num;
    }value;
    union{
        symrec * name;
        void * empty;
    }member;
}LRhand;



/*THE SYMBOL TABLE: A CHAIN OF 'STRUCT SYMREC'*/
extern symrec *sym_table;

//=========================================
//||        AUXILIARY FUNCTIONS          ||
//=========================================
void checkVariableStructure(symrec *);
void checkTypeStructure(type * );
void checkArrayStructure(array * );
void readTable(symrec *);

char * concat(char *, char *);
char * readArray(array *);

symrec * newRecordTable();
symrec *createSym(char const *, type *);
symrec *createSymStruct(char const *, type *, symrec **);
symrec *putsym(char const *, type *);
symrec *putsymStruct(char const *, type *, symrec **);
void updatesym(symrec*);
symrec *getsym(char const *);
symrec *getsymStruct(char const *, symrec *);
int checkArrayAccess(array *, ref *);
int* arrayElement(array *, ref *);
int typeChecking(symrec *);
int * Levaluate(LRhand *);
int Revaluate (LRhand *);
int assignment(LRhand *, LRhand *);
int validateStructAccess(char const *, char const *);

//=========================================
//||    VARIABLE CREATION FUNCTIONS      ||
//=========================================

basic * makeVar(const enum data_type);

//=====================================//
// PARSER FUNCTIONS
//=====================================//
array * makeArray(array *,int , const enum data_type);
array * m_array(array * , int , const enum data_type);

int checkExistance(symrec *, symrec *);


#endif	/* HEADER_H */
