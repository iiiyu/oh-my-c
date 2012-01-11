TARGET=sort_test

$(TARGET):main.c sort.c rand.c
	cc main.c sort.c rand.c -o $(TARGET)

.PHONY: all clean

all: $(TARGET) 

clean:
	rm -f *~
	rm -f a.out
	rm -rf $(TARGET)
