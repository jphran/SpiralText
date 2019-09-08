/*
Auth: Justin Francis
Class: CS3505
Assign: A2 SpiralText
Created: 9/6/19
Version: 0.1
Modified:


Description: A test program for spiral.cpp
a close copy of pdfExample.cpp
*/


/*
 * << Alternative PDF Library 1.0.0 >> -- text_demo2.c
 *
 * Copyright (c) 1999-2006 Takeshi Kanno <takeshi_kanno@est.hi-ho.ne.jp>
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.
 * It is provided "as is" without express or implied warranty.
 *
 * Modified by David Johnson and Justin Francis, University of Utah, 2016.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"

#include "HaruPDF.h"


// argc is the number of arguments. Argv is an array of character arrays, or C-style strings.
// If you call the program like ./pdfExample "Hello", then argv[1] would contain "Hello\0".
// argv[0] would be "pdfExample\0" - the name of the executing program.
int main (int argc, char ** argv)
{
    HaruPDF hp(argc, argv);

//************spiral*************
    unsigned int i;
    const char* sample = "exmaple text";
    double angle2 = 180;
    double rad1;
    double rad2;

    // Place characters one at a time on the page.
    for (i = 0; i < strlen (sample); i++) {
        float x;
        float y;
        // rad1 determines the angle of the letter on the page. rad2 is how far
        // around the circle you are. Notice that they are perpendicular and
        // thus not independent.
        //
        // Pay careful attention to what wants radians and what is degrees
        // between haru and spiral and math functions.
        rad1 = (angle2 - 90) / 180 * 3.141592;
        rad2 = angle2 / 180 * 3.141592;

        // The position of the character depends on the center point
        // plus the angle and the radius.
        x = 210 + cos(rad2) * 150;
        y = 300 + sin(rad2) * 150;
        // This ugly function defines where any following text will be placed
        // on the page. The cos/sin stuff is actually defining a 2D rotation
        // matrix.
        hp.writeToPDF(x,y,rad1,sample[i]);
        angle2 -= 10;
  }
    hp.savePDF();

    return 0;
}
