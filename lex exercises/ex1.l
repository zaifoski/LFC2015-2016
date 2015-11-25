%{
int c = 0;
%}
%%
[0-9]+	{c++;}
.
\n
%%

main(){
	yylex();
	printf("numeri totali %d\n",c);
}