run: main.o
	gcc -o run main.o
main.o:
	gcc -c main.c
rmobj:
	rm -rf *.o
clean:	
	rm -rf run *.o

prio.i:main.c
	gcc -E $^ -o $@ -I ${shell pwd}/..
