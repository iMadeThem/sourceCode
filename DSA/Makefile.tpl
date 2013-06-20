#----------------------
# To be changed
#----------------------
BIN =

SOURCE := \
	$(BIN).cpp

#----------------------
# Do not change
#----------------------
CC = g++

all: $(BIN)

$(BIN): $(SOURCE)
	$(CC) $(SOURCE) -o $(BIN)

clean:
	rm -f $(BIN)

#----------------------
