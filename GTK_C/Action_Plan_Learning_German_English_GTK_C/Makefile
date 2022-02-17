# Makefile
# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects



# Source, Executable, Includes, Library Defines
# Change this
ODIR = ./obj
    
# Change this    
LDIR = ./lib

# Change this
EXE = hellomake

# Change this
_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# Change this
_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Compiler, Linker Defines
# Change this
IDIR	= 	./include

RM      = 	/bin/rm -f
CC      = 	/usr/bin/gcc                       
# CFLAGS=-I.
CFLAGS	=	-I$(IDIR) -Wall -g


# Compile and Assemble C Source Files into Object Files
$(ODIR)/%.o: %.c $(DEPS)
	@echo "Checking.."
	$(CC) -c -o $@ $< $(CFLAGS)

# Link all Object Files with external Libraries into Binaries
$(EXE): $(OBJ)
	@echo "Creating object.."
	$(CC) -o $@ $^ $(CFLAGS)
	
# Clean Up Objects, Exectuables, Dumps out of source directory
.PHONY: clean

clean:
	@echo "Cleaning up..."
	$(RM) $(ODIR)/*.o *~ core $(IDIR)/*~ $(EXE)
