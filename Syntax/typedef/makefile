run:main.o
	gcc -o run main.o
main.o:main.c
	gcc -c main.c
info.txt:main.c
	gcc -D GOOD -E main.c -o info.txt
clean:
	rm *.o run *.txt
