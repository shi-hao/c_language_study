# 动态库，静态库  
  
动态链接和静态链接的区别：    
动态库不会编译进入可执行文件，可执行文件在运行的时候会在运行环境下动态加载库文件。  
静态连接会直接将库打包进入可执行文件。    
  
C程序编译和运行    
(1)gcc compile   
-l  指定库名    
-L  指定库的路径    
  
(2)runtime        
程序运行时，动态加载动态库。  
  
系统搜索动态库路径！  
<pre>
1. Directories listed in the executable’s rpath .  
2. Directories in the LD_LIBRARY_PATH environment variable, which contains  
   colon-separated list of directories (e.g., /path/to/libdir:/another/path )  
3. Directories listed in the executable’s runpath .  
4. The list of directories in the file /etc/ld.so.conf . This file can include other  
   files, but it is basically a list of directories - one per line.  
5. Default system libraries - usually /lib and /usr/lib (skipped if compiled  
   with -z nodefaultlib ).  
</pre>

linux ldd查看elf文件需要的库。  
ldd    elf-file    
