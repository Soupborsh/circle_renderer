CC?=cc

all: main.c
	$(CC) main.c -o main -Wall -O3
clean:
	rm image.pbm main
