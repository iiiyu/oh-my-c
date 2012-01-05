TARGET	= oh-my-c.tar.gz

$(TARGET):
	make -C linux-c/
	tar cpzf $(TARGET) --exclude=.git linux-c/

.PHONY: clean remove_bak debug release

debug: $(TARGET)

release:
	make -C linux-c/
	tar cpzf $(TARGET) --exclude=.git linux-c/

clean:
	rm -rf $(TARGET)
	make -C linux-c/ clean

remove_bak:
	find . -name "*~" | xargs rm
