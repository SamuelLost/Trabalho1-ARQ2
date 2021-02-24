all: exe

exe: main.o DECODER_THUMB.o
	gcc obj/main.o obj/DECODER_THUMB.o -o bin/exe

main.o: src/main.c
	gcc -c src/main.c -Iinc -o obj/main.o

DECODER_THUMB.o: src/DECODER_THUMB.c
	gcc -c src/DECODER_THUMB.c -Iinc -o obj/DECODER_THUMB.o

run:
	./bin/exe < entrada.in > saida.out

clean:
	rm obj/*.o bin/exe *.out
