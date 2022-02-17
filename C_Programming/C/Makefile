#Makefile to compile multiple C programs


# Source, Executable, Includes, Library Defines
# Change these parameters if needed!
SOURCES = $(wildcard *.c)
EXECS   = $(SOURCES:%.c=%)
IDIR	=   ./include

# Compiler, Linker Defines
RM      = 	/bin/rm -f
CC      = 	/usr/bin/gcc                       
CFLAGS	=	-I$(IDIR) -Wall -g

	
# Link all Object Files with external Libraries into Binaries
all: $(EXECS)


# Clean Up Objects, Exectuables, Dumps out of source directory
.PHONY: clean

clean:
	@echo "Cleaning up..."
	$(RM) *~ core $(IDIR)/*~ $(EXECS)
