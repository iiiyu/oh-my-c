TARGET= hello_test \
       string_test 1024_test time_test \
       thread1_test thread2_test thread3_test \
       callback_test


CFLAGS= -D_REENTRANT -I/usr/include/nptl

LIBS= -L/usr/lib/nptl -lpthread


%_test:%_test.o
	cc $(LIBS) -g $< -o $@ 

%_test.o:%_test.c
	cc $(CFLAGS) -c -g $< -o $@


.PHONY: all clean

all: $(TARGET) 

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f *~
	rm -f a.out
