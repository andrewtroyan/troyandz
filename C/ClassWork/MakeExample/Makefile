all: main.o funs.o
	gcc -o bin/app obj/main.o obj/funs.o

funs.o: funs.c folders
	gcc --std=c11 -o obj/funs.o -c funs.c

main.o: main.c folders
	gcc --std=c11 -o obj/main.o -c main.c

clean:
	rm -rf bin obj

folders:
	mkdir bin
	mkdir obj
