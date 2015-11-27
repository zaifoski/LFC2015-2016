%{
	int h = 0;
	int s= 0;
%}

%%
she  {s++; REJECT;}
he	{h++; REJECT;}
.
\n

%%
 int main(){
 	yylex();
 	printf("he : %d she: %d\n",h,s);
 }