run: object.o outline.o
	gcc object.o outline.o  -o run

object.o: main.c
	gcc -E main.c       -o preprocess.i
	gcc -S preprocess.i -o compile.s
	gcc -c compile.s    -o object.o

outline.o: outline.c
	gcc -c outline.c    -o outline.o

clean:
	rm -rf *.i  *.s  *.o run
