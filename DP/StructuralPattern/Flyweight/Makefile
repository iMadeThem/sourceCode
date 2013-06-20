#----------------------
# To be changed
#----------------------
BIN = Flyweight

SOURCE := \
	Flyweight.cpp \
	Flyweight.h \
	FlyweightFactory.cpp \
	FlyweightFactory.h \
	main.cpp

PATTERN = FlyweightPattern
SOURCE_PATTERN = $(PATTERN).cpp
#----------------------
# Do not change
#----------------------
CC = g++

all: $(BIN) $(PATTERN)

$(BIN): $(SOURCE)
	$(CC) $(SOURCE) -o $(BIN)

$(PATTERN): $(SOURCE_PATTERN)
	$(CC) $(SOURCE_PATTERN) -o $(PATTERN)

clean:
	rm -f $(BIN) $(PATTERN)

#----------------------
