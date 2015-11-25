
%%
[A-Z] |
[a-z]		{printf("%s - %d\n",yytext, (int)yytext[0]);}
.
\n
%%
