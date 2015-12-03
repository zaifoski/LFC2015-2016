%%

S: FUN;

FUN    : TYPE ID '(' PARAM ')' '{' BODY '}'      
      ;
PARAM    : PARAM ',' TYPE ID
    | TYPE ID
    |
    ;          
BODY    : BODY BODY
    | PARAM ';'
    | E ';'         
        | RETURN E ';'
        | 
    ;               
E    : ID '=' E
    | E '+' E
    | E '-' E
    | E '*' E
    | E '/' E        
    | ID
    | NUM    
    ;
