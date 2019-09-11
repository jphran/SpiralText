/*
Auth: Justin Francis
Class: CS3505
Assign: A2 SpiralText
Created: 9/6/19
Version: 1.0
Modified:


Description: A class for generating coordinates for a spiral text placement
*/

//**************************PREPROCESSOR**********************************
#include <cmath>
#include <math.h>
#include "Spiral.h"


//**************************CSTR**********************************
/*
Creates a Spiral object and initalizes it from the specified fields.
*/
Spiral::Spiral(double centerX, double centerY, double startRadius, double startAngDeg)
 : centerX_(centerX), centerY_(centerY), startAngDeg_(startAngDeg)
{
  //TODO: coord limits
  //limit initializers
  if(startRadius >= 50 && startRadius <= 200)
  {
    startRadius_ = startRadius;
  }
  else{startRadius_ = 100;}

  theta = ((-startAngDeg_+90)*(M_PI/180)); //sets starting angle
  dTheta = startRadius_/(B*startRadius_); //sets angle incrementation
  textX_ = centerX_ + (startRadius_-(B*theta)) * cos(theta); //starting point
  textY_ = centerY_ + (startRadius_-(B*theta)) * sin(theta);
  textAngDeg_ = -(theta - M_PI/2) * 180/M_PI; //sets first char angle
}


//**************************METHODS**********************************
/*
  postfix incrementation.
  internally advances the spiral char placement to its next position.
  works for spirals that fit on one 8.5 x 11in page.
*/
Spiral& Spiral::operator++()
{
  theta -= dTheta; //decrement
  //TODO: decrease dist between chars
  dTheta -= dTheta/(pow(B,3)); //reduce spacing as the spiral advances

  //archimedean spiral parameterized
  textX_ = centerX_ + (startRadius_-(B*theta)) * cos(theta);
  textY_ = centerY_ + (startRadius_-(B*theta)) * sin(theta);

  textAngDeg_ = (theta - M_PI/2) * 180/M_PI;

  return *this;
}

/*
  prefix incrementation.
  same as postfix.
*/
Spiral Spiral::operator++(int)
{
  Spiral incremented(*this);
  ++(*this);
  return incremented;
}

/*
returns the x coordinate of the next char in spiral. references bottom left
corner of page
*/
double Spiral::getTextX()
{
  return textX_;
}

/*
returns the y coordinate of the next char in spiral. references bottom left
corner of page
*/
double Spiral::getTextY()
{
  return textY_;
}

/*
returns the rotation of the next char in spiral relative to the vertical
in degrees
*/
double Spiral::getTextAngle()
{
  return textAngDeg_;
}
