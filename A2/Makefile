# Auth: Justin Francis
# Class: CS3505
# Assign: A2 SpiralText
# Created: 9/6/19
# Version: 0.1
# Modified:
#
#
# Description: A makefile because command line is hard

CC = g++
CFLAGS = -Wall -std=c++11
LIBHARU = ../libharu


spiralPDF: spiralPDF.cpp Spiral.cpp Spiral.h HaruPDF.h HaruPDF.cpp
	$(CC) $(CFLAGS) -o spiralPDF Spiral.cpp HaruPDF.cpp spiralPDF.cpp -I$(LIBHARU)/include -L$(LIBHARU)/src -lhpdfs

#TODO:
# spiralPDF: Spiral.o HaruPDF.o spiralPDF.cpp
# 	$(CC) $(CFLAGS) -o spiralPDF Spiral.o HaruPDF.o spiralPDF.cpp
#
# Spiral.o: Spiral.h Spiral.cpp
# 	$(CC) $(CFLAGS) -c Spiral.cpp
#
# HaruPDF.o: HaruPDF.h HaruPDF.cpp
# 	$(CC) $(CFLAGS) -c HaruPDF.cpp -I$(LIBHARU)/include -L$(LIBHARU)/src -lhpdfs


#clean and test
clean:
	rm spiralPDF *.o *.pdf

test:
	./spiralPDF "sample text J the quick brown fox jumped"
	okular spiralPDF.pdf
