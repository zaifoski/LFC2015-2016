CC = cc
LEX = lex
RM = rm -f

all: context1 context2 counter counter_wrong converter


context1: context1.o
	@echo "building context1"

	$(CC) -o $@ $@.o -ll
context1.o: context1.c

context1.c:
	$(LEX) -t contextsensitivity1.l > $@

context2: context2.o
	@echo "building context2"

	$(CC) -o $@ $@.o -ll
context2.o: context2.c

context2.c:
	$(LEX) -t contextsensitivity2.l > $@

counter: counter.o
	@echo "building counter"

	$(CC) -o $@ $@.o -ll

counter.o: counter.c

counter.c:
	$(LEX) -t find_he_she.l > $@

counter_wrong: counter_wrong.o
	@echo "building counter wrong"

	$(CC) -o $@ $@.o -ll

counter_wrong.o: counter_wrong.c

counter_wrong.c:
	$(LEX) -t find_he_she_wrong.l > $@


converter: converter.o
	@echo "building converter"

	$(CC) -o converter converter.o -ll

converter.o: converter.c

converter.c:
	$(LEX) -t csvtohtml.l > $@

clean:
	@echo "removing all file generated during all the builds"
	$(RM) converter.* converter
	$(RM) counter.* counter
	$(RM) counter_wrong.* counter_wrong
	$(RM) context1.* context1
	$(RM) context2.* context2
	$(RM) lex.yy.c
