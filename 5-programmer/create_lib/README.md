# 动态库，静态库        
      
## 动态库   
      
1.动态库命名规则      
以lib开头，加上自定义名字，加上.so，再加上时间版本号等信息。      
    
2.生成动态库    
      
3.动态库安装      
动态库安装，即将生成的动态库复制到系统库目录下，然后使用ldconfig更新库缓存。      
linux系统下，动态库的默认路径一般是/lib和/usr/lib，/usr/local/lib      
    
ldconfig工具？    
      
4.程序编译时调用动态库      
调用方法：  
使用-l参数调用，如动态库是libmyssl-1.0.0.so，那么在调用时可以使用-libmyssl-1.0.0来使用动    
态库，即可以省略掉开头的lib和结尾的.so    
  
编译时，调用动态库，gcc不会把动态库打包进可执行程序，只会做语法检查，也不会将    
动态库的路径体现在可执行程序中。    
  
为了提高使用的方便性，linux会在库路径下为动态库生成软件链接，比如库libssl.so.1.1，      
生成一个软件链接libssl.so指向库文件，当用户在编译可执行文件时，直接使用-lssl就可      
以调用到libssl.so.1.1，十分方便。      
    
头文件和库文件路径：  
(1)默认路径  
gcc有默认配置的头文件和库文件的搜索路径。  
头文件一般是/usr/include, /usr/local/include  
库文件一般是/lib,/usr/lib,/usr/local/lib  
可以查看gcc头文件和库文件搜索路径。  
  
(2)增加头文件和库文件路径  
头文件：  
Method 1: use CPATH (c or c++), C_INCLUDE_PATH (c only), CPLUS_INCLUDE_PATH  
(c++ only). For example: CPATH=/home/transang/my_libs_headers gcc -c foo.c -o  
foo.o.  
  
Method 2: use -I<dir_path> to gcc when compiling. For example: gcc  
-I/home/transang/my_libs_headers -c foo.c -o foo.o.  
  
库文件：  
Method 1: To add an directory to library linking search directories list, use  
LD_LIBRARY_PATH environment variable. For example:  
LD_LIBRARY_PATH=/home/transang/my_libs gcc foo.o bar.o -o foo  
  
Method 2: add flag -L<dir_path> to gcc when linking. For example: gcc  
-L/home/transang/my_libs foo.o bar.o -o foo.  
    
5.程序运行时加载动态库      
当启动一个ELF可执行文件时，系统会启动库加载器来加载程序需要的库，加载器的名字    
一般是/lib/ld-linux.so.X，其中X是版本号，加载器会加载所有其他所需的动态库。    
    
加载库路径：  
(1)LD_LIBRARY_PATH  
先去环境变量定义的路径下搜寻动态库  
  
(2)/etc/ld.so.conf  
这个文件定义了动态库的存储路径，加载器会去对应路径寻找动态库  
  
(3)默认路径  
一般是/lib,/usr/lib,/usr/local/lib  
  
在实际使用中，每次搜索文件夹是很低效的，linux引入了缓存机制，使用ldconfig      
工具会将指定文件夹下的动态库生成一个缓存文件(/etc/ld.so.cache)，缓存文件中      
是动态库和路径的对应关系，比如动态库libssl.so.1.1在路径/usr/lib下，缓存文件      
中会生成一条映射 libssl.so.1.1  /usr/lib/lissl.so.1.1，这样系统在加载动态库      
时，可以查找缓存文件，提高效率。      
      
**多版本动态库并存**      
多个版本的动态库，版本之间不兼容，不同的应用程序依赖于不同版本的库，如何解决这个问题？      
将多个版本的库复制到系统路径下即可，注意，在编译可执行文件时，要分清楚使用的是哪个版      
本的动态库，注意文件链接的问题！！      
      
**查看elf文件动态库信息**      
linux ldd查看elf文件需要的库。        
ldd    elf-file          
