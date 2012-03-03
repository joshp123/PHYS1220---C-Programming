# Wedit Makefile for project lucien
SRCDIR=c:\cdev\lucien
CFLAGS=-I"c:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	b5.obj

LIBS=
EXE=lucien.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\lucien.exe $(OBJS) $(LIBS)

# Build b5.c
B5_C=\

b5.obj: $(B5_C) $(SRCDIR)\b5.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\b5.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\lucien.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) lucien.exe
