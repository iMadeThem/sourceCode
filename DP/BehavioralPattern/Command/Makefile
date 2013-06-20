#----------------------
# To be changed
#----------------------
BIN = Command

SOURCE := \
	$(BIN).cpp \
	$(BIN).h \
	Receiver.cpp \
	Receiver.h \
	Invoker.cpp \
	Invoker.h \
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
