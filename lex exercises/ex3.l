%{
int c = 0;
int i= 0;
%}
%%
[0-9]+,[0-9]+	{c++;}
[0-9]+ i++;
.
\n
%%

main(){
	yylex();
	printf("numeri reali totali %d\n",c);
	printf("numeri interi totali %d\n",i);

}
