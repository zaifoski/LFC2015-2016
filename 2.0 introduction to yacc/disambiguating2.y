/*
	author Lorenzo Gramola
	original source yacc - Yet another compiler compiler
	example 2 on the rules for disambiguating grammars

	we can manage input like 
	a = b = c * d - e * f*g
*/

%token NAME
%right '='
%left '+' '-'
%left '*' '/'

%%

E 	:	E '=' E
	|	E '+' E
	|	E '-' E
	|	E '*' E
	|	E '/' E
	|	NAME
	;