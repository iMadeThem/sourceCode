#----------------------
# To be changed
#----------------------
BIN = Prototype

SOURCE := \
	Prototype.cpp \
	Prototype.h \
	main.cpp

SINGLE = PrototypePattern
SINGLE_SRC = PrototypePattern.cpp

#----------------------
# Do not change
#----------------------
CC = g++

all: $(BIN)

$(BIN): $(SOURCE)
	$(CC) $(SOURCE) -o $(BIN)

$(SINGLE): $(SINGLE_SRC)
	$(CC) $(SINGLE_SRC) -o $(SINGLE)

clean:
	rm -f $(BIN) $(SINGLE)

#----------------------
