run:main.o fun.o 
	gcc -o run  $^

#main.o: main.s
#	gcc -o main.o -c main.s  #汇编，生成目标文件，二进制文件（汇编器）
#main.s: main.i
#	gcc -o main.s -S main.i  #编译，生成汇编代码，（编译器）
#main.i:main.c
#	gcc -o main.i -E main.c  #预处理

%.o:%.c
	gcc -o $@ -c $<

clean:
	rm -rf *.o  *.s *.i run
