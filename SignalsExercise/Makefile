CC = gcc
CFLAGS = -Wall -Wextra -g

all: mysigcatch mysigcatchmodified


mysigcatch: mysigcatch.c
	$(CC) $(CFLAGS) -o mysigcatch mysigcatch.c

mysigcatchmodified: mysigcatchmodified.c
	$(CC) $(CFLAGS) -o mysigcatchmodified mysigcatchmodified.c


clean:
	rm -f mysigcatch mysigcatchmodified
