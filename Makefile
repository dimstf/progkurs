 .PHONY: all clean test


 all: build/main.o dinlib.so
	gcc -g3 build/main.o -L. dinlib.so -o bin/sorting
 build/main.o: src/main.c
	gcc -c src/main.c -o build/main.o
 build/IntVector.o: src/IntVector.c
	gcc -fPIC -c src/IntVector.c -o build/IntVector.o
 build/sorts.o: src/sorts.c
	gcc -fPIC -c src/sorts.c -o build/sorts.o
 dinlib.so: build/IntVector.o build/sorts.o
	gcc -shared -o dinlib.so build/IntVector.o build/sorts.o


 clean:
	rm build/IntVector.o build/sorts.o build/main.o


 test: bin/sorting
	bash bin/test.sh
