%START AA BB CC

%%
^a { ECHO; BEGIN AA;}
^b { ECHO; BEGIN BB;}
^c { ECHO; BEGIN CC;}

<AA>directory {printf("first");}
<BB>directory {printf("second");}
<CC>directory {printf("third");}

\n	{ECHO; BEGIN 0;}

%%
int main() {
  yylex();
  return 0;
}
