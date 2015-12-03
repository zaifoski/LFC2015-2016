/*
 	original source: yacc - yet another compiler compiler
 */

%token DING DONG DELL
%%
rhyme : sound place;

sound: DING DONG;

place: DELL;