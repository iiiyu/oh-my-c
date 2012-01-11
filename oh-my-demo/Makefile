TARGET=list_test




%_test:%_test.o
	cc -export-dynamic -g $< -o $@ 

%_test.o:%_test.c
	cc -c -g $< -o $@


.PHONY: all clean

all: $(TARGET) 

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f *~
	rm -f a.out
