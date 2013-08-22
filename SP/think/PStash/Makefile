#
# Makefile for 'PStashTest'.
#
# Type 'make' or 'make PStashTest' to create the binary.
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
default: PStashTest

PStashTest: $(OUT_DIR)/PStash.cpp.o $(OUT_DIR)/PStashTest.cpp.o
	@echo -n 'Linking PStashTest... '
	@$(CC) $(CFLAGS) -o PStashTest $(OUT_DIR)/PStash.cpp.o $(OUT_DIR)/PStashTest.cpp.o $(LIBS)
	@echo Done.

$(OUT_DIR)/PStash.cpp.o: PStash.cpp PStash.h ../require.h
	@echo -n 'Compiling PStash.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/PStash.cpp.o -c PStash.cpp
	@echo Done.

$(OUT_DIR)/PStashTest.cpp.o: PStashTest.cpp PStash.h ../require.h
	@echo -n 'Compiling PStashTest.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/PStashTest.cpp.o -c PStashTest.cpp
	@echo Done.

run:
	./PStashTest 

debug:
	gdb ./PStashTest

clean:
	@echo -n 'Removing all temporary binaries... '
	@rm -f PStashTest $(OUT_DIR)/*.o
	@echo Done.

clear:
	@echo -n 'Removing all temporary binaries... '
	@rm -f PStashTest $(OUT_DIR)/*.o
	@echo Done.

