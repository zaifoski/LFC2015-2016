%{
int c = 0;
%}
%%

I	{c++;}
V	{c+=5;}
X	{c+=10;}
L	{c+=50;}
C	{c+=100;}
D	{c+=500;}
M	{c+=1000;}
.
\n
%%

main(){
	yylex();
	printf("numeri totali %d\n",c);
}