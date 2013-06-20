#----------------------
# To be changed
#----------------------
BIN = Template

SOURCE := \
	Template.cpp \
	Template.h \
	main.cpp

PATTERN = TemplatePattern
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
