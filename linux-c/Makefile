TARGET=gthread_test hello_test \
       string_test 1024_test time_test \
       thread1_test thread2_test thread3_test \
       callback_test


CFLAGS= `pkg-config --cflags gtk+-2.0 gthread-2.0` -I/usr/include/ypkg2 -D_REENTRANT -I/usr/include/nptl

LIBS= `pkg-config --libs gtk+-2.0, gthread-2.0` -lypk -L/usr/lib/nptl -lpthread


%_test:%_test.o
	cc $(LIBS) -export-dynamic -g $< -o $@ 

%_test.o:%_test.c
	cc $(CFLAGS) -c -g $< -o $@


.PHONY: all clean

all: $(TARGET) 

clean:
	rm -f $(OBJS) $(TARGET)
	rm -f *~
	rm -f a.out
