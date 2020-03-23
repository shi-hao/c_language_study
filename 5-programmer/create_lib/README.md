# 动态库，静态库  
  
1.动态链接和静态链接的区别    
动态库不会编译进入可执行文件，可执行文件在运行的时候会在运行环境下动态加载库文件。  
静态连接会直接将库打包进入可执行文件。    

2.动/静态库名
静态库命名一般遵循如下规则：
以lib开头，以.a结束，lib + name + .a  

动态库命名一般遵循如下规则：
以lib开头，加上自定义名字，加上.so，再加上时间版本号等信息。

2.编译时指定库
使用gcc编译可执行程序时，使用如下参数来指定动/静态库
-l  指定库名    
-L  指定库的路径    
  
3.运行时加载库
静态库加载：
因为静态库是和可执行程序打包在一块的，所以，静态库不需要动态加载。

动态库加载：
编译时使用的动态库名称和运行时加载的动态库名称必须保持一致，不然运行时会报错，
提示无法找到对应的动态库。

**动态库个管理**
(1)动态库和可执行程序是分离的，由系统保存和管理。
(2)当编译好动态库后，使用make install安装动态库，make会将动态库文件拷贝到系统
   指定的安装目录下，然后调用ldconfig，在安装目录下生成一个软链接，链接到实际
   库文件，软连接一般都是动态库文件名的缩写，比如libmy.so.3，软链接一般是libmy.so。
   或者可以直接拷贝库文件到指定的目录下，然后ldconfig手动更新动态库软链接。
(3)当编译程序，需要用到某个动态库时，直接使用编译参数-lmy就可以链接到libmy.so.3。

**动态库保存路径**
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


**多版本动态库并存**


**查看elf文件动态库信息**
linux ldd查看elf文件需要的库。  
ldd    elf-file    
