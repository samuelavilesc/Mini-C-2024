calculadora : lex.yy.c main.c calculadora.tab.c
	gcc main.c lex.yy.c calculadora.tab.c -lfl -o calculadora

calculadora.tab.c calculadora.tab.h: calculadora.y
	bison -d -v calculadora.y

lex.yy.c: calculadora.l calculadora.tab.h
	flex calculadora.l

clean:
	rm -f calculadora calculadora.tab.c calculadora.tab.h lex.yy.cc

run: calculadora entrada.txt
	./calculadora entrada.txt