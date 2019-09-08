/*
Auth: Justin Francis
Class: CS3505
Assign: A2 SpiralText
Created: 9/6/19
Version: 0.1
Modified:

*/

#ifndef SPIRALTEXT_H
#define SPIRALTEXT_H

#include <cmath>

Class SpiralText
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
  SpiralText(double centerX, double centerY, double startRadius, double startAngDeg
  : centerX_(centerX), centerY_(centerY), startRadius_(startRadius), startAngDeg_(startAngDeg)){}

  /*
    internally advances the spiral to its next position.
    works for spirals that fit on one 8.5 x 11in page.
  */
  void operator++()
  {
    //TODO:
  }

  double getTextX()
  {
    return textX_;
  }

  double getTextY()
  {
    return textY_;
  }


  //returns degrees
  double getTextAngle()
  {
    return textAngDeg_;
  }

};
#endif
