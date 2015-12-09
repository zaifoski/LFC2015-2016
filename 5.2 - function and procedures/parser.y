/**
 * Lorenzo Massimo Gramola (2015)
*/

%{
    #include <stdio.h>

%}
%error-verbose



%start program


%%

program:
  opt_proc_list
  MAIN LCURLY
  opt_stmt_list
  RCURLY
  ;


dec:
    type VARIABLE SEMICOLON
    | type CONST VARIABLE EQUALS expr
    ;


type: B
      C
      ;

C :   /*empty*/
      | LBRACK INTEGER_V RBRACK C
      ;
opt_stmt_list:
      /*empty*/
      | stmt_list
      ;
opt_proc_list:
      /*empty*/
      | proc_list
      ;

proc_list:
        proc
        | proc_list proc
        ;
proc:
        opt_type VARIABLE LP form RP LCURLY
                opt_stmt_list
            RCURLY
        ;
opt_type:
        /*empty*/
        | B
        ;
B:      INT_T
        //| FLOAT_T
        | BOOL_T
        ;
form:
         /*empty*/
         |form_list
         ;
form_list:
        param
        | form COMMA param
        ;
param:  B VARIABLE
        ;
opt_actual_expr:
        /*empty*/
        |actual_expr
        ;
actual_expr:
        expr
        |actual_expr COMMA expr
        ;
stmt:
        SEMICOLON
        | dec
        | expr SEMICOLON
        | PRINT expr SEMICOLON
        | VARIABLE EQUALS expr SEMICOLON
        | WHILE LP expr RP stmt
        | IF LP expr RP stmt %prec IFX
        | IF LP expr RP stmt ELSE stmt
        | FOR LP VARIABLE EQUALS expr TO expr RP stmt
        | LCURLY stmt_list RCURLY
        ;


stmt_list:
        stmt
        | stmt_list stmt
        ;
expr:
        INTEGER_V
        //| FLOAT_V
        | BOOLEAN_V
        | EVAL VARIABLE LP opt_actual_expr RP
        | VARIABLE
        | MINUS expr %prec UMINUS
        | expr PLUS expr
        | expr MINUS expr
        | expr MULTIPLY expr
        | expr DIVIDE expr
        | expr LT expr
        | expr GT expr
        | expr GE expr
        | expr LE expr
        | expr NE expr
        | expr EQ expr
        | LP expr RP
        ;
