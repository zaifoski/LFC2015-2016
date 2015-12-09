
%left '-'
%left '*'

%token id

%%

E 	:		E '-' E
  | '-' E
  |		E '*' E
	|		id
	;
