### Makefile ###

all: Atv3

Atv3: Atv3.c
	gcc -Wall -g Atv3.c -o Atv3.exe

run: Atv3
	./Atv3.exe
