CXX = gcc
CXXFLAGS = -Wall -Wno-unused -Wextra -pedantic -g 
LDFLAGS =  -fsanitize=address

SRC = *.c opcodes/*.c
OBJ = $(SRC:.cc=.o)
TARGET = run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(LBLIBS)
	-./run
	rm run
clean:
	rm run
