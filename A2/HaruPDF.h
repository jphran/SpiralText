/*
Auth: Justin Francis
Class: CS3505
Assign: A2 SpiralText
Created: 9/6/19
Version: 0.1
Modified:

*/

#ifndef HARUPDF_H
#define HARUPDF_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"

class HaruPDF
{
private:
  HPDF_Doc  pdf;
  HPDF_Page page;
  char fname[256];
  HPDF_Font font;

public:
  HaruPDF(int argc, char **argv);
  void writeToPDF(double xPos, double yPos, double angleRad, char toWrite);
  void savePDF(void);
};
#endif
