echo 'compiling lex file ' $1
lex -o $1.yy.c $1.l 
cc -c -o $1.o $1.yy.c
cc $1.o -ll -o $1
echo 'removing uselss files' $1.yy.c ', ' $1.o
rm  $1.yy.c $1.o
