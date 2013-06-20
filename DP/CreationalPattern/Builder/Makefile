#----------------------
# To be changed
#----------------------
BIN = Builder

# NG
#SOURCE := BuilderPattern.cpp
# OK
#SOURCE := BuilderPatternPizza.cpp

SOURCE := \
	Car.cpp \
	Car.h \
	Builder.cpp \
	Builder.h \
	Director.cpp \
	Director.h \
	main.cpp

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
