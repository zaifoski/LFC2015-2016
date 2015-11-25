
%{
 int sum = 0;
%}

%%

[0-9]+ {sum+=atoi(yytext);}
\n
.

%%

int main(){
	yylex();
	printf("sum is %d\n", sum);
}
