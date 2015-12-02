CC = cc
LEX = lex
RM = rm -f

all: ex1_v1 ex1_v2 ex2_v2


ex1_v1: ex1_v1.o
	echo "building ".$@
	$(CC) $@.c

ex1_v1.o: ex1_v1.yy.c
	echo "building ".$@
	$(CC) -c -o $@ ex1_v1.yy.c

ex1_v1.yy.c:
	echo "building ".$@
	$(LEX) $@ -o $@ ex1_v1.l


clean:
	echo "target is empty"
