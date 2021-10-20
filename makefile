c = gcc
op = -Wall -Wextra
d = -D DEBUG
a = SDA2_TP4_TRENY_TEO.tar.gz

#GENERAL
clear :
	rm -rf *.e *.o *.tar.gz

all : exe debug

exe : main.e

debug : main_DEBUG.e

archive :
	tar -czvf $a *

# AVL
AVL.o : AVL.c
	$(c) $(op) -c AVL.c -o AVL.o

AVL_DEBUG.o : AVL.c
	$(c) $(op) $(d) -c AVL.c -o AVL_DEBUG.o
	
# MAIN
main.e : main.o AVL.o AVL.h
	$(c) $(op) main.o AVL.o -o main.e

main_DEBUG.e : main_DEBUG AVL_DEBUG.o AVL.h
	$(c) $(op) $(d) main_DEBUG.o AVL_DEBUG.o -o main_DEBUG.e

main.o : main.c
	$(c) $(op) -c main.c -o main.o

main_DEBUG.o : main.c
	$(c) $(op) $(d) -c main.c -o main_DEBUG.o