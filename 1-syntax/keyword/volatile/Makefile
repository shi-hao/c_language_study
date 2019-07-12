#gcc -On 编译优化

all: main.c
	#默认不启用优化
	gcc       -S main.c  -o   1.s 

	#优化代码
	gcc -O3   -S main.c  -o   1O3.s 

clean:
	rm -rf *.s
