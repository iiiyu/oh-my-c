TARGET=kmp_test

$(TARGET):matcher.o replace.o main.c
	cc  main.c matcher.o replace.o -o $(TARGET)

matcher.o:
	cc -c -g matcher.c matcher.h

replace.o:matcher.o
	cc -c -g replace.c replace.h matcher.o

.PHONY: all clean

all: $(TARGET) 

clean:
	rm -f *~
	rm -f a.out
	rm -rf *.o
	rm -rf *.gch
	rm -rf $(TARGET)
