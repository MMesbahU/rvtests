# Default value of FC in Makefile is f77,
# but it does not necessarily exist
HAS_F77:=$(shell command -v $(FC) 2>/dev/null)
ifndef HAS_F77
	FC=gfortran
endif
CXX?=g++


release: CXXFLAGS=-O2 -DNDEBUG
release: FCFLAGS=-O2 -DNDEBUG
debug: CXXFLAGS= -O0 -ggdb
debug: FCFLAGS=-O0 -ggdb

.SUFFIXES:

all: release
release: libMvtnorm.a
debug: libMvtnorm.a

libMvtnorm.a: mvtnorm.o mvt.o randomF77.o 
	$(AR) rcs $@ $^ 

mvtnorm.o: mvtnorm.cpp mvtnorm.h
	$(CXX) $(CXXFLAGS) -c mvtnorm.cpp -o mvtnorm.o

randomF77.o: randomF77.c
	$(CC) $(CXXFLAGS) -c randomF77.c

mvt.o: mvt.f
	$(FC) $(FCFLAGS) -c mvt.f

clean:
	rm -f *.o *.a
