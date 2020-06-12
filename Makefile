TARGET ?= bingdex
CC = clang++
FLG = -std=c++17 -I.

$(TARGET):
	$(CC) $(FLG) ./src/$(TARGET).cpp -o ./bin/$@

.PHONY: clean
clean:
	$(RM) ./bin/$(TARGET)

-include $(DEPS)
