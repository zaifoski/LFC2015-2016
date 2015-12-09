
%token bool IF ELSE id
%nonassoc S
%right ELSE

%%

S : IF '(' B ')' S  
	| IF '(' B ')'  S ELSE S 
	| E ;
B : bool ;
E : id ;