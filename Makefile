all: main

main: src/*.c src/*.h
	$(CC) -o main src/main.c src/cycle.c src/arc.c src/benchmark.c
