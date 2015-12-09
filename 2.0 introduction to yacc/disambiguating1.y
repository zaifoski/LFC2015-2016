/*
	author Lorenzo Gramola
	on the precedence of operators, example 1
	this grammar is ambiguous

*/

%left '+'
%left '*'
%token id

%%

E 	:		E '+' E
	|		E '*' E
	|		id
	;
