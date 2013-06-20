#----------------------
# To be changed
#----------------------
BIN = Iterator

SOURCE := \
	$(BIN).cpp \
	$(BIN).h \
	Aggregate.cpp \
	Aggregate.h \
	main.cpp

PATTERN = IteratorMethodPattern
SOURCE_PATTERN = $(PATTERN).cpp

PATTERN1 = IteratorOperatorPattern
SOURCE_PATTERN1 = $(PATTERN1).cpp

#----------------------
# Do not change
#----------------------
CC = g++

all: $(BIN) $(PATTERN) $(PATTERN1)

$(BIN): $(SOURCE)
	$(CC) $(SOURCE) -o $(BIN)

$(PATTERN): $(SOURCE_PATTERN)
	$(CC) $(SOURCE_PATTERN) -o $(PATTERN)

$(PATTERN1): $(SOURCE_PATTERN1)
	$(CC) $(SOURCE_PATTERN1) -o $(PATTERN1)

clean:
	rm -f $(BIN) $(PATTERN) $(PATTERN1)

#----------------------
