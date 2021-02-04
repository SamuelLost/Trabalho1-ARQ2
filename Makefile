all: exe

exe: main.o DECODE_ARM.o
	gcc obj/main.o obj/DECODE_ARM.o -o bin/exe

main.o: src/main.c
	gcc -c src/main.c -Iinc -o obj/main.o

DECODE_ARM.o: src/DECODE_ARM.c
	gcc -c src/DECODE_ARM.c -Iinc -o obj/DECODE_ARM.o

run:
	./bin/exe

clean:
	rm obj/*.o bin/exe
