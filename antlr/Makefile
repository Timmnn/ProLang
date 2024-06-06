# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -g -I/usr/local/include/antlr4-runtime -I/opt/homebrew/Cellar/llvm/18.1.6/include

# Linker flags
LDFLAGS = -L/opt/homebrew/Cellar/llvm/18.1.6/lib -L/usr/local/lib

# Libraries to link against
LDLIBS = -lantlr4-runtime -lLLVM

# Source files
SRCS = main.cpp ProLexer.cpp ProParser.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Output binary
OUT = main.bin

all: $(OUT)

$(OUT): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUT)