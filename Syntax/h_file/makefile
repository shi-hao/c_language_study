run: main.o
	gcc main.o -o run
main.o: main.c
	gcc -E main.c        -o preprocess.i
	gcc -S preprocess.i  -o compile.s
	gcc -c compile.s     -o main.o
clean:
	rm -rf *.i *.o  *.s run
