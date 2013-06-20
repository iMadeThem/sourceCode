#----------------------
# To be changed
#----------------------
BIN = Singleton

SOURCE := \
	Singleton.cpp \
	Singleton.h \
	main.cpp

PATTERN = SingletonPattern
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
