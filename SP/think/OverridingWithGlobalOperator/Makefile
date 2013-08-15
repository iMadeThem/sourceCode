#
# Makefile for 'IntegerTest'.
#
# Type 'make' or 'make IntegerTest' to create the binary.
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
default: IntegerTest

IntegerTest: $(OUT_DIR)/Integer.cpp.o $(OUT_DIR)/IntegerTest.cpp.o
	@echo -n 'Linking IntegerTest... '
	@$(CC) $(CFLAGS) -o IntegerTest $(OUT_DIR)/Integer.cpp.o $(OUT_DIR)/IntegerTest.cpp.o $(LIBS)
	@echo Done.

$(OUT_DIR)/Integer.cpp.o: Integer.cpp Integer.h ../require.h
	@echo -n 'Compiling Integer.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/Integer.cpp.o -c Integer.cpp
	@echo Done.

$(OUT_DIR)/IntegerTest.cpp.o: IntegerTest.cpp Integer.h
	@echo -n 'Compiling IntegerTest.cpp... '
	@$(CC) $(CFLAGS) -o $(OUT_DIR)/IntegerTest.cpp.o -c IntegerTest.cpp
	@echo Done.

run:
	./IntegerTest 

debug:
	gdb ./IntegerTest

clean:
	@echo -n 'Removing all temporary binaries... '
	@rm -f IntegerTest $(OUT_DIR)/*.o
	@echo Done.

clear:
	@echo -n 'Removing all temporary binaries... '
	@rm -f IntegerTest $(OUT_DIR)/*.o
	@echo Done.

