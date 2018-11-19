assembly_file: main.c
	gcc                   -S main.c -o NonVol.s 
#	gcc -O                -S main.c -o NonVol_O.s 
#	gcc -O0                -S main.c -o NonVol_O0.s 
#	gcc -O1                -S main.c -o NonVol_O1.s 
#	gcc -O2                -S main.c -o NonVol_O2.s 
#	gcc -O3                -S main.c -o NonVol_O3.s 
	gcc      -D VolatileSW -S main.c -o Vol.s
	gcc -O0  -D VolatileSW -S main.c -o Vol_O0.s 
	gcc -O1  -D VolatileSW -S main.c -o Vol_O1.s 
	gcc -O2  -D VolatileSW -S main.c -o Vol_O2.s 
	gcc -O3  -D VolatileSW -S main.c -o Vol_O3.s 
#	gcc -O  -D VolatileSW -S main.c -o Vol_O.s 
clean:
	rm -rf *.s
