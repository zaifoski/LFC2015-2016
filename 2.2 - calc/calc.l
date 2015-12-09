/** calculator calc.l
 * origin source by Tom Niemann at epaperpress.com/lexandyacc
 * revision Lorenzo Massimo Gramola (2014)
 * revision Lorenzo Massimo Gramola (2015) 

 */
%{
    #include <stdlib.h>
    #include "calc.h" 
    #include "y.tab.h" 

    void yyerror(char *);
%}

%%

[a-z]           {
                    yylval.sIndex = *yytext - 'a';
                    return VARIABLE;
                }
0               {
                    yylval.iValue = atoi(yytext);
                    return INTEGER;
                }
[1-9][0-9]*     {
                    yylval.iValue = atoi(yytext);
                    return INTEGER;
                }

[-+()<>=*/;{}.]   { return *yytext; }

">="            return GE;
"<="            return LE;
"=="            return EQ;
"!="            return NE;
"while"         return WHILE;
"if"            return IF;
"else"          return ELSE;
"print"         return PRINT;


[ \t\n]         ;/* skip whitespace */

.               yyerror("Unknown character");

%%

int yywrap(void) {
    return 1;
}