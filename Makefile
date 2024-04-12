all:
	g++ -I src/include -L src/lib -o main main.c -l mingw32 -l SDL2main -l SDL2 -l SDL2_image