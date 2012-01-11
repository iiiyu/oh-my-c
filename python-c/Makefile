all:libtest.so

libtest.so:libtest.o
	gcc -shared libtest.o -o libtest.so

libtest.o:multiply.c
	gcc -c -fPIC multiply.c -o libtest.o


clean:
	rm -rf *o
	rm -rf *~

