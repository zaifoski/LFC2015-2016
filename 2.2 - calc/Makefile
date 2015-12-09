# A Makefile for simple lex and yacc examples
# original file by http://www.csee.umbc.edu/courses/331/fall11/hw/hw4/calc/Makefile
# more at
# Comment out the proper lines below according to the scanner and
# parser generators available in your system

LEX = lex
YACC = yacc -d
# LEX = flex 
# YACC = bison -d

# We assume that your C-compiler is called cc

CC = cc

# calc is the final object that we will generate, it is produced by
# the C compiler from the y.tab.o and from the lex.yy.o

interpreter: y.tab.o lex.yy.o
	$(CC) -o interpreter y.tab.o lex.yy.o calcInterpreter.c -ll -lm 

compile: y.tab.o lex.yy.o
	$(CC) -o compiler y.tab.o lex.yy.o calcCompiler.c -ll -lm 

graph: y.tab.o lex.yy.o
	$(CC) -o graph y.tab.o lex.yy.o calcGraph.c -ll -lm

dot: y.tab.o lex.yy.o
	$(CC) -o dot y.tab.o lex.yy.o calcDot.c -ll -lm
# These dependency rules indicate that 
# (1) lex.yy.o depends on lex.yy.c and y.tab.h
# (2) lex.yy.o and y.tab.o depend on calc.h.
# Make uses the dependencies to figure out what rules must be run when
# a file has changed.

lex.yy.o: lex.yy.c y.tab.h
#lex.yy.o y.tab.o: calc.h

## This rule will use yacc to generate the files y.tab.c and y.tab.h
## from our file calc.y

y.tab.c y.tab.h: calc.y
	$(YACC) -v calc.y

## this is the make rule to use lex to generate the file lex.yy.c from
## our file calc.l

lex.yy.c: calc.l
	$(LEX) calc.l

## Make clean will delete all of the generated files so we can start
## from scratch

clean:
	-rm -f *.o lex.yy.c *.tab.*  calc *.output
