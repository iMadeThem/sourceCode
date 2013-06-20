#----------------------
# To be changed
#----------------------
BIN = Composite

SOURCE := \
	Component.cpp \
	Component.h \
	Composite.cpp \
	Composite.h \
	Leaf.cpp \
	Leaf.h \
	main.cpp

PATTERN = CompositePattern
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
