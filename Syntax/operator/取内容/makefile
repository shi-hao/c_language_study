run:    main.o
	gcc  -o run       main.o
main.o: main.c
	gcc  -o main.o -c main.c
assembly-code:
	gcc -S main.c -o ass.s
clean:
	rm -rf *.o run
