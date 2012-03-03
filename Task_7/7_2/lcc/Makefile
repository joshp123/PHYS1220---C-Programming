# Wedit Makefile for project 7_2_prime_sieve
SRCDIR=c:\cdev\task_7\7_2
CFLAGS=-I"C:\lcc\include"  -g2 
CC=$(LCCROOT)\bin\lcc.exe
LINKER=$(LCCROOT)\bin\lcclnk.exe
OBJS=\
	7_2_prime_sieve.obj

LIBS=
EXE=7_2_prime_sieve.exe

$(EXE):	$(OBJS) Makefile
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\7_2_prime_sieve.exe $(OBJS) $(LIBS)

# Build 7_2_prime_sieve.c
7_2_PRIME_SIEVE_C=\
	c:\lcc\include\_syslist.h\

7_2_prime_sieve.obj: $(7_2_PRIME_SIEVE_C) $(SRCDIR)\7_2_prime_sieve.c
	$(CC) -c $(CFLAGS) $(SRCDIR)\7_2_prime_sieve.c

link:
	$(LINKER)  -subsystem console -o $(SRCDIR)\lcc\7_2_prime_sieve.exe $(OBJS) $(LIBS)

clean:
	del $(OBJS) 7_2_prime_sieve.exe
