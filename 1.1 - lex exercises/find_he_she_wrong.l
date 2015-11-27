%{
int h = 0;
int s = 0;
%}

%%
she						{s++;}
he						{h++;}
\n						|
.						;


%%
int main() {
  yylex();
  printf("found in the text %d occurrences of she\nfound in the text %d occurrences of he\n",s,h);

  return 0;
}
