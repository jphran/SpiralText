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
  char buf[2];
  HPDF_Page_BeginText (page);
  // Their example sets font twice. Probably some kind of mistake. Fix it or do what they do.
  font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
  HPDF_Page_SetFontAndSize (page, font, 30);

  // This ugly function defines where any following text will be placed
  // on the page. The cos/sin stuff is actually defining a 2D rotation
  // matrix.
  HPDF_Page_SetTextMatrix(page,
                          cos(angleRad), sin(angleRad), -sin(angleRad), cos(angleRad),
                          xPos, yPos);

  // C-style strings are null-terminated. The last character must a 0.
  buf[0] = toWrite; // The character to display
  buf[1] = 0;
  HPDF_Page_ShowText (page, buf);
}

void HaruPDF::savePDF(void)
{
  HPDF_Page_EndText (page);

  /* save the document to a file */
  HPDF_SaveToFile (pdf, fname);

  /* clean up */
  HPDF_Free (pdf);
}
