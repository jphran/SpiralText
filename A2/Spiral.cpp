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
#include <iostream>
#include "Spiral.h"

Spiral::Spiral(double centerX, double centerY, double startRadius, double startAngDeg)
 : centerX_(centerX), centerY_(centerY), startRadius_(startRadius), startAngDeg_(startAngDeg)
{
  //TODO: put in radius limits and coords
  theta = ((-startAngDeg_+90)*(M_PI/180));
  dTheta = startRadius_/(B*startRadius_);
  textX_ = centerX_ + (startRadius_-(B*theta)) * cos(theta);
  textY_ = centerY_ + (startRadius_-(B*theta)) * sin(theta);
  textAngDeg_ = (theta - M_PI/2) * 180/M_PI;
}


/*
  internally advances the spiral to its next position.
  works for spirals that fit on one 8.5 x 11in page.
*/
Spiral& Spiral::operator++()
{
  theta -= dTheta;
  dTheta -= dTheta/(pow(B,3)); //TODO: decrease dist between chars

  //archimedean spiral
  textX_ = centerX_ + (startRadius_-(B*theta)) * cos(theta);
  textY_ = centerY_ + (startRadius_-(B*theta)) * sin(theta);

  textAngDeg_ = (theta - M_PI/2) * 180/M_PI;

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
