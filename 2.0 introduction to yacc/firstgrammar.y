/*
 author LG
 this file should be the minimum that can be provided to Yacc
 */

%%

E : E '+' T | T;
T: T '*' F | F;
F: '(' E ')' | 'id';
