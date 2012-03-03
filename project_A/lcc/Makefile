# Wedit Makefile for project quadratic
SRCDIR=c:\cdev\project_a
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	quadratic.obj

LIBS=
EXE=quadratic.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\quadratic.exe $(OBJS) $(LIBS)

# Build quadratic.c
QUADRATIC_C=\
	c:\lcc\include\_syslist.h\
	c:\lcc\include\tgmath.h\

quadratic.obj: $(QUADRATIC_C) $(SRCDIR)\quadratic.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\quadratic.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\quadratic.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) quadratic.exe
