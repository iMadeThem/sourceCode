#----------------------
# To be changed
#----------------------
BIN = BinarySearchTree

SOURCE := \
	$(BIN).cpp

BIN_1 = NextNode
SOURCE_1 = $(BIN_1).cpp
#----------------------
# Do not change
#----------------------
CC = g++

all: $(BIN) $(BIN_1)

$(BIN): $(SOURCE)
	$(CC) $(SOURCE) -o $(BIN)

$(BIN_1): $(SOURCE_1)
	$(CC) $(SOURCE_1) -o $(BIN_1)

clean:
	rm -f $(BIN) $(BIN_1)

#----------------------
