/*
Auth: Justin Francis
Class: CS3505
Assign: A2 SpiralText
Created: 9/6/19
Version: 1.0
Modified:

*/

//**********************************PREPROCESSOR********************************
#ifndef SPIRAL_H
#define SPIRAL_H

#include <cmath>
#include <math.h>

//**********************************CLASS********************************
class Spiral
{
private:
  const int B = 5;
  double dTheta;
  double theta;
  double centerX_;
  double centerY_;
  double startRadius_;
  double startAngDeg_;
  double textX_;
  double textY_;
  double textAngDeg_;

public:
  Spiral(double centerX, double centerY, double startRadius, double startAngDeg);
  Spiral& operator++();
  Spiral operator++(int);
  double getTextX();
  double getTextY();
  double getTextAngle();

};
#endif
