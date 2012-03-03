# Wedit Makefile for project 7_1_arrays
SRCDIR=c:\cdev\task_7\7_1
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	7_1_arrays.obj

LIBS=
EXE=7_1_arrays.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\7_1_arrays.exe $(OBJS) $(LIBS)

# Build 7_1_arrays.c
7_1_ARRAYS_C=\
	c:\lcc\include\_syslist.h\

7_1_arrays.obj: $(7_1_ARRAYS_C) $(SRCDIR)\7_1_arrays.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\7_1_arrays.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\7_1_arrays.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) 7_1_arrays.exe
