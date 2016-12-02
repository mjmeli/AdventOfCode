all:
	bison -y -d -o day2.y.c day2.y
	flex -o day2.lex.c day2.lex
	gcc -o day2 day2.y.c day2.lex.c -ll
	./day2 input.txt

clean:
	$(RM) *.c *.h day2
