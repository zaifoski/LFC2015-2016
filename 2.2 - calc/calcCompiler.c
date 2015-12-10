/** calculator calcCompiler.c
 * origin source by Tom Niemann at epaperpress.com/lexandyacc
 * revision Lorenzo Massimo Gramola (2014)
 */

#include <stdio.h>
#include "calc.h"
#include "y.tab.h"

static int lbl;

int ex(nodeType *p){
    int lbl1, lbl2;
    
    if(!p) return 0;
    switch (p->type) {
        case typeCon:
            printf("\tpush\t%d\n",p->con.value); //push the value of a constant on the stack
            break;
        case typeId:
            printf("\tpush\t%c\n",p->id.i + 'a');
            break;
        case typeOpr:
            switch (p->opr.oper) {
                case WHILE:
                    printf("L%03d:\n",lbl1 = lbl++);
                    ex(p->opr.op[0]);//evaluate/execute the "boolean" expression
                    printf("\tjz\tL%03d\n", lbl2 = lbl++);
                    ex(p->opr.op[1]);
                    printf("\tjmp\tL%03d\n",lbl1);
                    printf("L%03d:\n",lbl2);
                    break;
                case IF:
                    ex(p->opr.op[0]);
                    if(p->opr.nops > 2){
                    /* we are processing and if (then) else */
                    /* we have to manage the if branch and the else branch providing the flow control on the single stack, thus using two labels*/
                        printf("\tjz\tL%03d\n", lbl1=lbl++); //jz = jump if zero
                        ex(p->opr.op[1]);
                        printf("\tjmp\tL%03d\n",lbl2=lbl++);
                        printf("L%03d:\n",lbl1);
                        ex(p->opr.op[2]);
                        printf("L%03d:\n",lbl2);
                    }
                    else{
                        /*if in a single branch, we should check that opr.nops == 1 but for the sake of simplicity we will omit it
                        */
                        printf("\tjz\tL%03d\n", lbl1 = lbl++);
                        ex(p->opr.op[1]);
                        printf("L%03d:\n",lbl1);
                    }
                    break;
                case PRINT:
                    ex(p->opr.op[0]); //evaluate the expression and put it on the stack
                    printf("\tprint\n"); //thus print it
                    break;
                case '=':
                    ex(p->opr.op[1]); //evaluate expression and push it on the stack
                    printf("\tpop\t%c\n", p->opr.op[0]->id.i + 'a'); //pop out the variable/identifier by consuming a value on the stack - namely consumes the value of opr.op[1] and binds it to the identifier
                    break;
                case UMINUS:
                    ex(p->opr.op[0]);
                    printf("\tneg\n");
                    break;
                default: //match operators with 2 operands - we know our grammar and we know how it is done, we don't have operation with more than 2 operators. since this are operators we have to push it on the stack before consuming them
                    //if is a constant will be pushed by typeCon ---> push 10
                    //if is a id will be pushed by typeID --> push x
                    ex(p->opr.op[0]); //push operators on the stack
                    ex(p->opr.op[1]);
                    switch (p->opr.oper) {
                        case'+':
                            printf("\tadd\n");
                            break;
                        case'-':
                            printf("\tsub\n");
                            break;
                        case'*':
                            printf("\tmul\n");
                            break;
                        case'/':
                            printf("\tdiv\n");
                            break;
                        case'<':
                            printf("\tcompLT\n");
                            break;
                        case'>':
                            printf("\tcompGT\n");
                            break;
                        case GE:
                            printf("\tcompGE\n");
                            break;
                        case LE:
                            printf("\tcompLE\n");
                            break;
                        case NE:
                            printf("\tcompNE\n");
                            break;
                        case EQ:
                            printf("\tcompEQ\n");
                            break;
                    }
            }
    }
    return 0;
}