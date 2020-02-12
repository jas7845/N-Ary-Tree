#
# Created by gmakemake (Ubuntu Jul 25 2014) on Mon Mar 25 16:59:04 2019
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Default flags (redefine these with a header.mak file if desired)
CXXFLAGS =	-ggdb
CFLAGS =	-ggdb
CLIBFLAGS =	-lm
CCLIBFLAGS =	
########## End of default flags


CPP_FILES =	
C_FILES =	N-Ary.c main.c offspring.c trimit.c while.c
PS_FILES =	
S_FILES =	
H_FILES =	N-Ary.h trimit.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	N-Ary.o trimit.o 

#
# Main targets
#

all:	main offspring while 

main:	main.o $(OBJFILES)
	$(CC) $(CFLAGS) -o main main.o $(OBJFILES) $(CLIBFLAGS)

offspring:	offspring.o $(OBJFILES)
	$(CC) $(CFLAGS) -o offspring offspring.o $(OBJFILES) $(CLIBFLAGS)

while:	while.o $(OBJFILES)
	$(CC) $(CFLAGS) -o while while.o $(OBJFILES) $(CLIBFLAGS)

#
# Dependencies
#

N-Ary.o:	N-Ary.h
main.o:	N-Ary.h
offspring.o:	N-Ary.h trimit.h
trimit.o:	trimit.h
while.o:	

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm -f $(OBJFILES) main.o offspring.o while.o core

realclean:        clean
	-/bin/rm -f main offspring while 
