CXX = clang
CXXFLAGS = -Wall -Wno-newline-eof -pedantic -g `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -lSDL2_image -lSDL2_ttf -lm
LDFLAGS =  -fsanitize=address

SRC = *.c opcodes/*.c mappers/*.c
OBJ = $(SRC:.cc=.o)
TARGET = run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)
clean:
	rm run
