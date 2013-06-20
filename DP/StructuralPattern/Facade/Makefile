#----------------------
# To be changed
#----------------------
BIN = Facade

SOURCE := \
	Facade.cpp \
	Facade.h \
	main.cpp

PATTERN = FacadePattern
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
