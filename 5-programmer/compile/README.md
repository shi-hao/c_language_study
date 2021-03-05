<pre>

文件说明：
主要有6个文件，如下。
  main.c         --->  源码文件
  ountline.h     --->  自定义头文件
  preprocess.txt --->  预处理输出文件
  compile.s      --->  编译输出文件
  object.o       --->  汇编输出文件
  outline        --->  链接生成的可执行文件
--------------------------------------------
1.预处理
gcc -E main.c -o preprocess.txt  //生成预处理文件

2.编译
gcc -S main.c         -o compile.s   //由源文件生成编译的汇编文件
gcc -S preprocess.txt -o compile.s   //由预处理文件生成编译的汇编文件

3.汇编
gcc -c main.c    -o object.o    //由源文件生成汇编的目标（机器码）文件
gcc -c compile.s -o object.o    //由汇编文件生成汇编的目标（机器码）文件

4.链接
gcc main.c   -o outline   //由源文件经预处理，编译，汇编，链接生成可执行文件
gcc object.o -o outline   //链接目标文件生成可执行文件

C语言编译过程?结果工具说明？ldd，readelf等

</pre>
