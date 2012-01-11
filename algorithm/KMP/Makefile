TARGET=kmp_test

$(TARGET):matcher.c matcher.h
	cc  matcher.c matcher.h -o $(TARGET)

.PHONY: all clean

all: $(TARGET) 

clean:
	rm -f *~
	rm -f a.out
	rm -rf $(TARGET)
