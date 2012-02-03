TARGET	= oh-my-c.tar.gz

$(TARGET):
	make -C linux-c/
	make -C python-c/
	make -C oh-my-demo/
	make -C algorithm/
#	tar cpzf $(TARGET) --exclude=.git linux-c/

.PHONY: clean remove_bak debug release

debug: $(TARGET)

release:
	make -C linux-c/
	make -C python-c/
	make -C oh-my-demo/
	make -C algorithm/
	tar cpzf $(TARGET) --exclude=.git linux-c/

clean:
	rm -rf $(TARGET)
	rm -rf *~
	make -C linux-c/ clean
	make -C python-c/ clean
	make -C oh-my-demo/ clean
	make -C algorithm/ clean

remove_bak:
	find . -name "*~" | xargs rm
