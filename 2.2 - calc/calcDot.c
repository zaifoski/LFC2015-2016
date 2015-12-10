/* source code courtesy of Frank Thomas Braun
 * found at epaperpress.com/lexandyacc
 * revision Lorenzo Massimo Gramola (2014)
 * revision Lorenzo Massimo Gramola (2015): DOT syntax for graph
 */

/* Generation of the graph of the syntax tree */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calc.h"
#include "y.tab.h"


char ** label = NULL;
char ** graph = NULL;
int lcurr = 0;
int gcurr = 0;
int l_size = 1;
int g_size = 1;
char * graphName = "tree_graph";
int gcounter = 0;
char * label_format = "\t%d [label=\"%s\"]\n";
char * graph_arrow_format = "\t%d -- %d\n";
/* interface for drawing (can be replaced by "real" graphic using GD or other) */
void graphInit (void);
void graphFinish();
void graphLablel (char *s, int uid);
void graphDrawArrow (int uid_from, int uid_to);

/* recursive drawing of the syntax tree */
void exNode (nodeType *p);

/*****************************************************************************/

/* main entry point of the manipulation of the syntax tree */
int ex (nodeType *p) {
    graphInit ();
    exNode (p); //recursive drawing
    graphFinish();
    return 0;
}


void exNode (nodeType *p)
{
    char *s;            /* node text */
    int k;
    if (!p) return;
    
    switch(p->type) {
        case typeCon:
            s = malloc(sizeof(char*));
            sprintf (s, "c(%d)", p->con.value); break;
        case typeId:
            s = malloc(sizeof(char*));
            sprintf (s, "id(%c)", p->id.i + 'A'); break;
        case typeOpr:
            switch(p->opr.oper){
                //define label
                case WHILE:     s = "while"; break;
                case IF:        s = "if";    break;
                case PRINT:     s = "print"; break;
                case ';':       s = "[;]";     break;
                case '=':       s = "[=]";     break;
                case UMINUS:    s = "[_]";     break;
                case '+':       s = "[+]";     break;
                case '-':       s = "[-]";     break;
                case '*':       s = "[*]";     break;
                case '/':       s = "[/]";     break;
                case '<':       s = "[<]";     break;
                case '>':       s = "[>]";     break;
                case GE:        s = "[>=]";    break;
                case LE:        s = "[<=]";    break;
                case NE:        s = "[!=]";    break;
                case EQ:        s = "[==]";    break;
            }
            break;
    }
    
    /* node is leaf */
    if (p->type == typeCon || p->type == typeId || p->opr.nops == 0) {
        graphLablel(s,p->uid);
        return;
    }

    /* node has children - for each children draw arrow and then draw children
     */
    for (k = 0; k < p->opr.nops; k++) {
        graphLablel(s,p->uid);
        graphDrawArrow(p->uid, p->opr.op[k]->uid);
        exNode (p->opr.op[k]);
    }

}

/* interface for drawing */

#define lmax 200
#define cmax 200

/**
 initializes label and graph
 */
void graphInit (void) {
    label = (char**)malloc(100 * sizeof(char*));
    graph = (char**)malloc(100 * sizeof(char*));
}

/**
 flush label and graph in a file or to console
 free used memeory
 increment graphcounter
 */
void graphFinish() {
    FILE *fp;
    char * filename;
    char * gname;
    int size = snprintf(NULL, 0, "%s%d", graphName, gcounter);
    gname = (char*)malloc(size * sizeof(char));
    sprintf(gname,"%s%d", graphName, gcounter);
    size = snprintf(NULL, 0, "%s%d.dot", graphName, gcounter);
    filename =(char*)malloc((size) * sizeof(char));
    sprintf(filename,"%s%d.dot", graphName, gcounter);
    fp = fopen(filename,"w");
    if (fp == NULL) {
        fprintf(stderr, "Can't open output file %s!\n",filename);
        exit(1);
    }
    
    //syntax of Dot is graph graphname {...}
    fprintf(fp,"graph %s{\n",gname);
    for (int i=0; i<gcurr; i++) {
        fprintf(fp,"%s\n", graph[i]);
        if(graph[i]!=NULL)
            free(graph[i]);
    }
    for (int j=0; j<lcurr; j++) {
        fprintf(fp,"%s\n", label[j]);
        if(label[j]!=NULL)
            free(label[j]);
    }
    //closing }
    fprintf(fp,"}\n");
    fclose(fp);
    //free(fp);
    //reset counters for array position
    lcurr = 0;
    gcurr = 0;
    //reset counter for malloc
    l_size = 1;
    g_size = 1;
    //increment counter for graph
    gcounter++;
}

void graphLablel (char *s, int uid) {
    if(lcurr == l_size){
        l_size++;
        char **tmp = (char **) realloc(label, (l_size) * sizeof(char*));
        if(!tmp){
            printf("can't allocate more memory.. i'm gonna close my self and go to bed..\n");
            exit(0);
        }else{
            label = tmp;
        }
    }
    int size = snprintf(NULL, 0, label_format, uid, s);
    char * slabel = (char*)malloc(size * sizeof(char));
    sprintf(slabel,label_format, uid, s);
    label[lcurr++]=slabel;

}

void graphDrawArrow (int uid_from, int uid_to) {
    if(gcurr == g_size){
        g_size++;
        char **tmp = (char **) realloc(graph, (g_size) * sizeof(char*));
        if(!tmp){
            printf("can't allocate more memory.. i'm gonna close my self and go to bed..\n");
            exit(0);
        }else{
            graph = tmp;
        }
    }
    int size = snprintf(NULL, 0, graph_arrow_format, uid_from, uid_to);
    char * adjacent = (char*)malloc(size * sizeof(char));
    sprintf(adjacent,graph_arrow_format, uid_from, uid_to);
    graph[gcurr++]=adjacent;

}

