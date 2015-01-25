all: main.o numberFunctions.o
	gcc -o bin/app obj/main.o obj/numberFunctions.o

numberFunctions.o: numberFunctions.c folders
	gcc --std=c11 -o obj/numberFunctions.o -c numberFunctions.c

main.o: main.c folders
	gcc --std=c11 -o obj/main.o -c main.c

clean: 
	rm -rf bin obj

folders:
	mkdir bin
	mkdir obj 
