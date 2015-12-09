/*

	Another way - same precendence but.. shift will win by the parser rules.

*/

%token bool IF ELSE id
%right IF ELSE


%%

S : IF '(' B ')' S  %prec IF| IF '(' B ')'  S ELSE S | E ;
B : bool ;
E : id ;