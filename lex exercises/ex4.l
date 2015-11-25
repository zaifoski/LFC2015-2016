%{
int c = 0;
%}
%%
[0-9]+	{ c+=atoi(yytext);}
.
\n
%%

int main(){
	yylex();
	printf("somma vale %d\n",c);
}