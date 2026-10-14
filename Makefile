#Compiler
CXX = c++
#Flags
CXXFLAGS = -Wall -o2
#Source Directory
SRCDIR = src

# target
TARGET = slm

# Sources files
SRCS = main.cpp class1.cpp class2.cpp

# Object files
OBJS = $(SRCDIR)/main.o $(SRCDIR)/class1.o $(SRCDIR)/class2.o

# Default rule to build and run the executable
all: $(TARGET) 

# Rule to link object files into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Which headers each object file depends on
main.o: class1.h class2.h
class1.o: class1.h class2.h
class2.o: class2.h


# Clean up generated files
clean:
	rm -f $(SRCDIR)/*.o $(TARGET)

.PHONY: all clean