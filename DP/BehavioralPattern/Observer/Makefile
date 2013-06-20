#----------------------
# To be changed
#----------------------
BIN = Observer

SOURCE := \
	$(BIN).cpp \
	$(BIN).h \
	Subject.cpp \
	Subject.h \
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
