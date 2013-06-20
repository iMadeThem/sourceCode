#----------------------
# To be changed
#----------------------
BIN = Interpret

SOURCE := \
	$(BIN).cpp \
	$(BIN).h \
	Context.cpp \
	Context.h \
	main.cpp

PATTERN = InterpreterPattern
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
