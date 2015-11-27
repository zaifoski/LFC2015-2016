%START AA BB CC

%%
^a						{ECHO; BEGIN AA;}
^b						{ECHO; BEGIN BB;}
^c						{ECHO; BEGIN CC;}
\n						{ECHO; BEGIN 0;}

<AA>directory			printf("first");
<BB>directory			printf("second");
<CC>directory			printf("third");

%%
int main() {
  yylex();
  return 0;
}
