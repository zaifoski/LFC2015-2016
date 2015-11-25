
%%

[a-z]		{printf("%c",yytext[0]+3);}
.
\n
%%

int main(){
	yylex();
	printf("\n")
}