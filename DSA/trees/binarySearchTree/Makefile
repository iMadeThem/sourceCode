#----------------------
# To be changed
#----------------------
BIN = BinarySearchTree

SOURCE := \
	$(BIN).cpp

BIN_1 = NextNode
SOURCE_1 = $(BIN_1).cpp

BIN_2 = VerifyBinarySearchTrees
SOURCE_2 = $(BIN_2).cpp
#----------------------
# Do not change
#----------------------
CC = g++

all: $(BIN) $(BIN_1) $(BIN_2)

$(BIN): $(SOURCE)
	$(CC) $(SOURCE) -o $(BIN)

$(BIN_1): $(SOURCE_1)
	$(CC) $(SOURCE_1) -o $(BIN_1)

$(BIN_2): $(SOURCE_2)
	$(CC) $(SOURCE_2) -o $(BIN_2)

clean:
	rm -f $(BIN) $(BIN_1) $(BIN_2)

#----------------------
