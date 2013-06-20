#----------------------
# To be changed
#----------------------
BIN = Visitor

SOURCE := \
	$(BIN).cpp \
	$(BIN).h \
	Element.cpp \
	Element.h \
	main.cpp

PATTERN = $(BIN)Pattern
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
