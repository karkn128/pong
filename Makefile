CXX = g++
CXXFLAGS = -std=c++0x -Wall -Wextra -Werror -pedantic -g #-Weffc++

ifeq "$(origin GCC4_V)" "environment"
# ldflags for Solaris
LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++ -lncursesw
CXXFLAGS += -D_SOLARIS_
else
# ldflags for Linux, Ubuntu 13.04 need "sudo apt-get install ncurses-dev"
LDFLAGS = -lncurses
endif




# type 'make all' or 'gmake all' to build everything
all: pong

pong: pong.o console.o paddle.o ball.o
	$(CXX) $^ $(LDFLAGS) -o $@

# to build an *.o file we need corresponding *.cc file
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

# to clean up compiler-generated files
clean:
	\rm -f *.o *.stackdump a.out hello_world hello_colors pong

# to clean up real good
zap: clean
	\rm -f *~
