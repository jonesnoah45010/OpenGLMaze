CC = clang
CFLAGS = -Wall -Wextra -std=c99 -O2
LIBS = -lglfw -lGLEW -framework OpenGL -lm
SRC = main.c
OUT = OpenGLMaze

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -f $(OUT)
