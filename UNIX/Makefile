TARGET ?= bingdex
CC = g++
FLG = -std=c++17 -I. -loath -lcurl

$(TARGET):
	$(CC) $(FLG) ./src/$(TARGET).cpp -o ./bin/osx/$@

.PHONY: clean
clean:
	$(RM) ./bin/$(TARGET)

-include $(DEPS)
