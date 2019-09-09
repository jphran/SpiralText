/*
Auth: Justin Francis
Class: CS3505
Assign: A2 SpiralText
Created: 9/6/19
Version: 0.1
Modified:

*/

#ifndef SPIRAL_H
#define SPIRAL_H

#include <cmath>

class Spiral
{
private:
  double centerX_;
  double centerY_;
  double startRadius_;
  double startAngDeg_;
  double textX_;
  double textY_;
  double textAngDeg_;

public:
  Spiral(double centerX, double centerY, double startRadius, double startAngDeg);
  void operator++();
  double getTextX();
  double getTextY();
  double getTextAngle();

};
#endif
