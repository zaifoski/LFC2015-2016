/*
 author LG
 this file is the minimum that can be provided to Yacc
 */
%token id

%%

E : E '+' T | T;
T: T '*' F | F;
F: '(' E ')' | id;
