sintactico : lex.yy.c main.c sintactico.tab.c listaSimbolos.c listaCodigo.c
	gcc -g main.c lex.yy.c sintactico.tab.c listaSimbolos.c listaCodigo.c -lfl -o sintactico

sintactico.tab.c sintactico.tab.h: sintactico.y
	bison -d -v sintactico.y

lex.yy.c: lexico.l sintactico.tab.h
	flex lexico.l

clean:
	rm -f sintactico sintactico.tab.c sintactico.tab.h lex.yy.cc

run: sintactico pruebamc.txt
	./sintactico pruebamc.txt > salida.s