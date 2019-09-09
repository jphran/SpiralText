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
#include <math.h>
#include "Spiral.h"

Spiral::Spiral(double centerX, double centerY, double startRadius, double startAngDeg)
 : centerX_(centerX), centerY_(centerY), startRadius_(startRadius), startAngDeg_(startAngDeg)
{
  //TODO: put in radius limits and coords
  theta = 0;
  dTheta = startRadius_/400;
  textX_ = centerX_ + cos(startAngDeg_*(M_PI/180))*startRadius_;
  textY_ = centerY_ + sin(startAngDeg_*(M_PI/180))*startRadius_;
}


/*
  internally advances the spiral to its next position.
  works for spirals that fit on one 8.5 x 11in page.
*/
Spiral& Spiral::operator++()
{
  //archimedean spiral
  theta += dTheta;
  // dTheta -= dTheta/B; //TODO: decrease dist between chars
  textX_ = centerX_ + (startRadius_+(B*theta)) * cos(theta);
  textY_ = centerY_ + (startRadius_+(B*theta)) * sin(theta);
  // textX_
  textAngDeg_ += ((M_PI/180)*theta);
  return *this;
}

Spiral Spiral::operator++(int)
{
  Spiral result(*this);
  ++(*this);
  return result;
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
