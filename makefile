all: refuge

main.o : main.c gcc -c main.c o- main.o

animl.o: animal.c animal.h gcc -c animal -o animal.o

fichier.o: fichier.c fchier.h gcc -c fichier.c -o fichier.o

search.o: search.c search.h gcc -c search.c -o search.o
