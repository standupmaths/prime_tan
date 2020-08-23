CC=gcc
L=-lm -lgmp

default: cf_convergents.c
	$(CC) cf_convergents.c $(L) -o convergents

