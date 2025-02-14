CC?=cc

all: main.c circles.c image.c
	$(CC) main.c circles.c image.c -o main -Wall -O3
clean:
	rm image.pbm main
