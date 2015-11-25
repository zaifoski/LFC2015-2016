%{
int c = 0;
%}
%%
[0-9]+,[0-9]+	{c++;}
.
\n
%%

main(){
	yylex();
	printf("numeri reali totali %d\n",c);
}