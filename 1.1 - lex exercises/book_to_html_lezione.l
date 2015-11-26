%%
[0-9]+	{printf("<td>%s</td>",yytext);}
\n		{printf("</tr><tr>");}
. 
%%
int main(){
	printf("<html>");
	printf("<table><tr>");
	yylex();
	printf("</tr></table>");
	printf("</html>");
}