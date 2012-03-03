# Wedit Makefile for project 6_3_temps_intervals
SRCDIR=c:\cdev\task_6\6_3
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	6_3_temps_intervals.obj

LIBS=
EXE=6_3_temps_intervals.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\6_3_temps_intervals.exe $(OBJS) $(LIBS)

# Build 6_3_temps_intervals.c
6_3_TEMPS_INTERVALS_C=\
	c:\lcc\include\_syslist.h\

6_3_temps_intervals.obj: $(6_3_TEMPS_INTERVALS_C) $(SRCDIR)\6_3_temps_intervals.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\6_3_temps_intervals.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\6_3_temps_intervals.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) 6_3_temps_intervals.exe
