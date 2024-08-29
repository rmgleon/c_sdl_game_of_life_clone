build:
	gcc -Wall -std=c23 ./src/*.c `sdl2-config --libs --cflags` -lm -o app

run:
	./app

clean:
	rm app