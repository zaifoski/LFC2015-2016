%{
/* Convert csv to html          */
%}

%%
[0-9]+					{printf("<td> "); ECHO;}
","       				{printf("</td> "); }
\n         				{printf("</td></tr> \n <tr>"); }

%%
int main() {
  printf("%s\n","<html>");
  printf("%s\n","<table>\n<tr>\n");
  yylex();
  printf("</tr>\n</table>\n");
  printf("</html>\n");
  return 0;
}
