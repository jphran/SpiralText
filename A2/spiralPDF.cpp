/*
Auth: Justin Francis
Class: CS3505
Assign: A2 SpiralText
Created: 9/6/19
Version: 1.0
Modified:


Description: the main in A2. This takes in the command line args and returns
spiral test pdf art
*/


//**********************************PREPROCESSOR********************************
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hpdf.h"

#include "HaruPDF.h"
#include "Spiral.h"



//********************************** MAIN********************************
// argc is the number of arguments. Argv is an array of character arrays, or C-style strings.
// If you call the program like ./pdfExample "Hello", then argv[1] would contain "Hello\0".
// argv[0] would be "pdfExample\0" - the name of the executing program.
int main (int argc, char ** argv)
{
  //parameters for the example spiral
    const int XCEN = 210;
    const int YCEN = 300;
    const int STARTRAD = 100;
    const int STARTANGDEG = 0;

    HaruPDF hp(argc, argv);
    Spiral sp(XCEN, YCEN, STARTRAD, STARTANGDEG);

    unsigned int i;

    // Place characters one at a time on the page.
    for (i = 0; i < strlen (argv[1]); i++) {
      hp.writeToPDF(sp.getTextX(),sp.getTextY(),(sp.getTextAngle()), argv[1][i]); 
      sp++;
    }

    hp.savePDF();

    return 0;
}
