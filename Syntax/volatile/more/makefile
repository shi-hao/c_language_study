#gcc使用 -On 来打开代码编译优化，大写字母O，n为0-3表示优化的级别
assembly_file: main.c
#	gcc                   -S main.c -o NonVol.s 
#	gcc -O                -S main.c -o NonVol_O.s 
#	gcc -O0                -S main.c -o NonVol_O0.s 
#	gcc -O1                -S main.c -o NonVol_O1.s 
#	gcc -O2                -S main.c -o NonVol_O2.s 
#	gcc -O3                -S main.c -o NonVol_O3.s 
#	gcc      -D VolatileSW -S main.c -o Vol.s
#	gcc -O0  -D VolatileSW -S main.c -o Vol_O0.s 
#	gcc -O1  -D VolatileSW -S main.c -o Vol_O1.s 
#	gcc -O2  -D VolatileSW -S main.c -o Vol_O2.s 
#	gcc -O3  -D VolatileSW -S main.c -o Vol_O3.s 
#	gcc -O  -D VolatileSW -S main.c -o Vol_O.s 
	gcc                    -S main.c -o 1.s 
	gcc     -O3            -S main.c -o 1_O3.s 

#	gcc          -D out_run          -o run     main.c
#	gcc     -O3  -D out_run          -o run_O3  main.c
clean:
	rm -rf *.s
