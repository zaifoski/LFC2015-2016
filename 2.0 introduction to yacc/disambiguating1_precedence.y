/*
	author Lorenzo Gramola
	on the precedence of operators, example 1

	NOTE: This time we give operators two different precedence
	what does happen if we have E + E * E
	check it with the yacc -v options and follow the parser moves

	0 -> 2 -> 4 -> 6 -> 5 -> 7 -> reduce by E : E * E .. and so on and so forth..
*/

%token id
%left '+' 
%left '*'

%%

E 	:		E '+' E
	|		E '*' E
	|		id
	;
