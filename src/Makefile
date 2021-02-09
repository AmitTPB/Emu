CXX = gcc
CXXFLAGS = -Wall -Wno-unused -Wextra -pedantic -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = *.c opcodes/*.c
OBJ = $(SRC:.cc=.o)
TARGET = run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm run