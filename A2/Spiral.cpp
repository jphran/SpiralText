/*
Auth: Justin Francis
Class: CS3505
Assign: A2 SpiralText
Created: 9/6/19
Version: 0.1
Modified:


Description: A class for generating coordinates for a spiral
*/


#include <cmath>
#include "Spiral.h"

Spiral::Spiral(double centerX, double centerY, double startRadius, double startAngDeg)
 : centerX_(centerX), centerY_(centerY), startRadius_(startRadius), startAngDeg_(startAngDeg) {}

/*
  internally advances the spiral to its next position.
  works for spirals that fit on one 8.5 x 11in page.
*/
void Spiral::operator++()
{
  //TODO:
}

double Spiral::getTextX()
{
  return textX_;
}

double Spiral::getTextY()
{
  return textY_;
}


//returns degrees
double Spiral::getTextAngle()
{
  return textAngDeg_;
}
