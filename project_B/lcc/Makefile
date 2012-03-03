# Wedit Makefile for project sumsquares
SRCDIR=c:\cdev\project_b
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	least_squares_fit.obj

LIBS=
EXE=sumsquares.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\sumsquares.exe $(OBJS) $(LIBS)

# Build least_squares_fit.c
LEAST_SQUARES_FIT_C=\

least_squares_fit.obj: $(LEAST_SQUARES_FIT_C) $(SRCDIR)\least_squares_fit.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\least_squares_fit.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\sumsquares.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) sumsquares.exe
