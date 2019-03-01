# 动态库  
## 编译  
编译时，如何指定动态库的名字和位置  


## 运行  
运行时，如何寻找动态库位置?  

一般而言，linux按照如下顺序搜寻动态库位置。  
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
