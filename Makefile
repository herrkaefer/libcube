#  =========================================================================
#  libcube makefile
#
#  Copyright (c) 2016, Yang LIU <gloolar@gmail.com>
#  =========================================================================

IDIR = /usr/local/include
ODIR = build
SRCDIR = src
DEMODIR = demo
TARGETDIR = bin

CC = gcc
CFLAGS = -I$(IDIR) -g -Wall
# CFLAGS += -DWITHSTATS
CFLAGS += -O3
CFLAGS += -std=c99

LDIR = -L/usr/local/lib
LIBS = -lm
# LIBS += -lczmq -lzmq

_MODULES = arrayi \
	       arrayset \
	       arrayu \
	       date_ext \
		   evol \
		   hash \
		   listu \
		   listx \
		   matrixd \
	       matrixu \
	       numeric_ext \
	       queue \
	       deps/pcg/entropy \
	       rng \
	       string_ext \
	       timer

_OBJS = $(_MODULES:=.o)
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))
LIBTARGET = libbbc.a
TESTOBJS = $(OBJS) $(ODIR)/selftest.o
TESTTARGET = $(TARGETDIR)/selftest

.PHONY: clib cdll test clean

$(ODIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)

test: $(TESTOBJS)
	$(CC) -o $(TESTTARGET) $(TESTOBJS) $(CFLAGS) $(LDIR) $(LIBS)
	$(TESTTARGET)

clib: $(OBJS)
	ar rcs $(LIBTARGET) $(OBJS)

cdll: $(OBJS)
	$(CC) -shared -o $@ $^ -Wl,--out-implib,$(LIBTARGET) $(LDIR) $(LIBS)

clean:
	rm -rf $(TARGETDIR)/* *.dll *.a py/*so $(ODIR)/* py/*.c
