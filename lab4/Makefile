#
# Makefile för bruteforcelösning
#

CCC	= g++ -std=c++11
LFLAGS	= -L/usr/lib/x86_64-linux-gnu -lSDL -lm

all: pointplot.cc brute.cc Point.o
	$(CCC) -o brute brute.cc Point.o $(LFLAGS)
	$(CCC) -o pointplot pointplot.cc Point.o $(LFLAGS)

Point.o: Point.cc Point.h
	$(CCC) -c Point.cc

clean:
	@ \rm -rf *.o core

zap: clean
	@ \rm -f fast *~
