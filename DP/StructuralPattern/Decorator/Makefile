#----------------------
# To be changed
#----------------------
BIN = Decorator

SOURCE := \
	Decorator.cpp \
	Decorator.h \
	main.cpp

PATTERN = DecoratorPattern
SOURCE_PATTERN = DecoratorPattern.cpp

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
