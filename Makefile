all: main

main:
	gcc -Wall -I src/include -L src/lib ./src/libs/*.c -o main main.c -l mingw32 -l SDL2main -l SDL2 -l SDL2_image