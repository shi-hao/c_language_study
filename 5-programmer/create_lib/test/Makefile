########################################################
#
# compiling every c file to corresponding excutable file 
#
#######################################################
CC := gcc
CFLAGS := -c

#lib path, relative path or absolute path
#LIB_PATH:=../
#LIB_PATH:=/home/bleach/myproject/c_language_study/Programmer/create_lib/lib
LIB_PATH:=/home/bleach/myproject/c_language_study/5-programmer/create_lib/lib

#lib name
LIB_NAME:=plus.1.0

#get all .c files name in current dir
SRCS := $(wildcard *.c)  

#raplace .c to .o in all files
OBJS := $(patsubst %.c, %.o, $(SRCS)) 

#replace .c to .elf in all files
TARGET := $(patsubst %.c, %.elf, $(SRCS)) 

all:$(TARGET)


#compiling all .c files to corresponding .elf excutable files
$(TARGET): %.elf : %.c
	$(CC)  $^ -L $(LIB_PATH) -l$(LIB_NAME) -o  $@ 

print:
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(TARGET)

#clean all .elf files
clean:
	rm *.elf
