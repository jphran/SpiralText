# Auth: Justin Francis
# Class: CS3505
# Assign: A2 SpiralText
# Created: 9/6/19
# Version: 1.0
# Modified:
#
#
# Description: A makefile because command line is hard

CC = g++
CFLAGS = -Wall -std=c++11
LIBHARU = ../libharu

spiralPDF: Spiral.o HaruPDF.o spiralPDF.cpp
	$(CC) $(CFLAGS) -o spiralPDF Spiral.o HaruPDF.o -I$(LIBHARU)/include -L$(LIBHARU)/src -lhpdfs spiralPDF.cpp

Spiral.o: Spiral.h Spiral.cpp
	$(CC) $(CFLAGS) -c Spiral.cpp

HaruPDF.o: HaruPDF.h HaruPDF.cpp
	$(CC) $(CFLAGS) -c HaruPDF.cpp -I$(LIBHARU)/include -L$(LIBHARU)/src -lhpdfs


#clean and test
clean:
	rm spiralPDF *.o *.pdf

test:
	./spiralPDF "sample text: ab abusu ad usum non valet consequentia decessit sine prole superstite haha";
