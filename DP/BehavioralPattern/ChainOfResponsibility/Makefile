#----------------------
# To be changed
#----------------------
BIN = ChainOfResponsibility

SOURCE := \
	Handle.cpp \
	Handle.h \
	main.cpp

PATTERN = $(BIN)Pattern
SOURCE_PATTERN = $(PATTERN).cpp

PATTERN1 = ChainAndCompositePattern
PATTERN1_SRC = ChainAndCompositePattern.cpp
#----------------------
# Do not change
#----------------------
CC = g++

all: $(BIN) $(PATTERN) $(PATTERN1)

$(BIN): $(SOURCE)
	$(CC) $(SOURCE) -o $(BIN)

$(PATTERN): $(SOURCE_PATTERN)
	$(CC) $(SOURCE_PATTERN) -o $(PATTERN)

$(PATTERN1): $(PATTERN1_SRC)
	$(CC) $(PATTERN1_SRC) -o $(PATTERN1)

clean:
	rm -f $(BIN) $(PATTERN) $(PATTERN1)

#----------------------
