C_SRC = $(wildcard *.c)
C_TAR = $(patsubst %.c, %, $(C_SRC))

CPP_SRC = $(wildcard *.cpp)
CPP_TAR = $(patsubst %.cpp, %, $(CPP_SRC))

BUILD_DIR = ./build
CC = gcc
CXX = g++
CFLAGS = -lgtest -lpthread -Wall -g
CXXFLAGS = -lgtest -lpthread -Wall -g
RM = rm -f
OBJS = $(BUILD_DIR)/
.PHONY:	clean all
$(CPP_TAR): %:%.cpp
	$(CXX) $^ -o $@  $(CXXFLAGS)

mk_dir:
	if [ ! -d $(BUILD_DIR) ];then mkdir $(BUILD_DIR);fi #每行命令在一个单独的shell中执行
clean:
	@$(RM) test *.o

all: mk_dir $(C_TAR) $(CPP_TAR)



