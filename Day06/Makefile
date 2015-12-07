all:
	bison -y -d -o day6.y.c day6.y
	flex -o day6.lex.c day6.lex
	gcc -std=gnu99 -o day6 day6.y.c day6.lex.c -ll
	./day6 input.txt

run:
	./day6 input.txt

test:
	./day6 input_test.txt

clean:
	$(RM) *.c *.h day6
