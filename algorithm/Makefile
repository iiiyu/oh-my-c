TARGET	= 

all:
	make -C sort/
	make -C KMP/

.PHONY: clean remove_bak debug release

debug: $(TARGET)

release:
	make -C sort/
	make -C KMP/

clean:
	rm -rf $(TARGET)
	rm -rf *~
	make -C sort/ clean
	make -C KMP/ clean

remove_bak:
	find . -name "*~" | xargs rm
