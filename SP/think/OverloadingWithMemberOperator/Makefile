#
# Makefile for 'ByteTest'.
#
# Type 'make' or 'make ByteTest' to create the binary.
# Type 'make clean' or 'make clear' to delete all temporaries.
# Type 'make run' to execute the binary.
# Type 'make debug' to debug the binary using gdb(1).
#

# build target specs
CC = g++
CFLAGS = -O3 
OUT_DIR = release_build
LIBS =

# first target entry is the target invoked when typing 'make'
default: ByteTest

ByteTest: $(OUT_DIR)/ByteTest.cpp.o
	@echo -n 'Linking ByteTest... '
	@$(CC) $(CFLAGS) -o ByteTest $(OUT_DIR)/ByteTest.cpp.o $(LIBS)
	@echo Done.

$(OUT_DIR)/ByteTest.cpp.o: ByteTest.cpp Byte.h ../require.h
	@echo -n 'Compiling ByteTest.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/ByteTest.cpp.o -c ByteTest.cpp
	@echo Done.

run:
	./ByteTest 

debug:
	gdb ./ByteTest

clean:
	@echo -n 'Removing all temporary binaries... '
	@rm -f ByteTest $(OUT_DIR)/*.o
	@echo Done.

clear:
	@echo -n 'Removing all temporary binaries... '
	@rm -f ByteTest $(OUT_DIR)/*.o
	@echo Done.

