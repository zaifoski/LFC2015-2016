/*
	author Lorenzo Gramola
	on the precedence of operators, example 1
	this grammar is ambiguous

*/

%token id

%%

E 	:		E '+' E
	|		E '*' E
	|		id
	;
