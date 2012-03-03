# Wedit Makefile for project ex3
SRCDIR=m:\cdev
CFLAGS=-I"Q:\lccwin7.v01\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	var.obj

LIBS=
EXE=ex3.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\ex3.exe $(OBJS) $(LIBS)

# Build var.c
VAR_C=\

var.obj: $(VAR_C) $(SRCDIR)\var.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\var.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\ex3.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) ex3.exe
