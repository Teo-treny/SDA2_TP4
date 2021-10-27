c = gcc
op = -Wall -Wextra
d = -D DEBUG
a = SDA2_TP4_TRENY_TEO.tar.gz

# GENERAL
all : exe debug

clean :
	rm -rf *.e *.o *.tar.gz Dot/*.dot Png/*.png

super-clean :
	make clean
	rm -rf html latex doxygen-awesome-css Doxyfile

exe : main.e

debug : main_DEBUG.e

# UTILITAIRE
archive :
	tar -czvf $a *

doxyfile :
	make super-clean
	doxycss.sh

# AVL
AVL.o : AVL.c
	$(c) $(op) -c AVL.c -o AVL.o

AVL_DEBUG.o : AVL.c
	$(c) $(op) $(d) -c AVL.c -o AVL_DEBUG.o
	
# TEST_AVL
test_AVL.o : test_AVL.c
	$(c) $(op) -c test_AVL.c -o test_AVL.o

# MAIN
main.e : main.o AVL.o test_AVL.o AVL.h test_AVL.h
	$(c) $(op) main.o AVL.o test_AVL.o -o main.e

main_DEBUG.e : main_DEBUG.o AVL_DEBUG.o test_AVL.o AVL.h test_AVL.h
	$(c) $(op) $(d) main_DEBUG.o AVL_DEBUG.o test_AVL.o -o main_DEBUG.e

main.o : main.c
	$(c) $(op) -c main.c -o main.o

main_DEBUG.o : main.c
	$(c) $(op) $(d) -c main.c -o main_DEBUG.o

