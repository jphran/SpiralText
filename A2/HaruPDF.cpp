/*
Auth: Justin Francis
Class: CS3505
Assign: A2 SpiralText
Created: 9/6/19
Version: 0.1
Modified:


Description: A facade wrapper class for Haru PDF lib cause its trash
*/
#include "HaruPDF.h"

HaruPDF::HaruPDF(int argc, char **argv)
{
  strcpy(fname, argv[0]);
  strcat(fname, ".pdf");

  pdf = HPDF_New(NULL, NULL);
  /* add a new page object. */
  page = HPDF_AddPage (pdf);
  HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
//    print_grid  (pdf, page);
  font = HPDF_GetFont (pdf, "Helvetica", NULL);
  HPDF_Page_SetTextLeading (page, 20);
  HPDF_Page_SetGrayStroke (page, 0);
}

void HaruPDF::writeToPDF(double xPos, double yPos, double angleRad, char toWrite)
{
  /* text along a circle */
  double angle2 = 180;
  double rad1;
  double rad2;
  unsigned int i;
  const char* sample = "sample text the quick brown fox jumped";

  HPDF_Page_BeginText (page);
  // Their example sets font twice. Probably some kind of mistake. Fix it or do what they do.
  font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
  HPDF_Page_SetFontAndSize (page, font, 30);
  // Place characters one at a time on the page.
  for (i = 0; i < strlen (sample); i++) {
      char buf[2];
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
      HPDF_Page_SetTextMatrix(page,
                              cos(rad1), sin(rad1), -sin(rad1), cos(rad1),
                              x, y);

      // C-style strings are null-terminated. The last character must a 0.
      buf[0] = sample[i]; // The character to display
      buf[1] = 0;
      HPDF_Page_ShowText (page, buf);
      angle2 -= 10.0; // change the angle around the circle
  }
}

void HaruPDF::savePDF(void)
{
  HPDF_Page_EndText (page);

  /* save the document to a file */
  HPDF_SaveToFile (pdf, fname);

  /* clean up */
  HPDF_Free (pdf);
}
