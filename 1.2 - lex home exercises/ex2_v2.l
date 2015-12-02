
%%

[A-Za-z]					; // just don't match the preceding part of the real quoted string 
\"(\\.|[^\\"])*\"			{
									printf("matchied a string with the given specification\n");
									printf("%s\n", yytext);

									}

%%

int main(){
	yylex();
	printf("\n");
	return 0;
}