#include <iostream>
#include <stdio.h>

int main()
  int blanks, tabs, newlines;
  int c;
  bool done = FALSE;
  int lastchar = 0;
  int symb = 0;

  blanks = 0;
  tabs = 0;
  newlines = 0;

  while(done == FALSE)
  {
    c = getchar();

    if(c == ' ')
      ++blanks;
        else

    if(c == '\t')
      ++tabs;
        else

    if(c == '\n')
      ++newlines;
        else


    if(c == EOF)
    {
      if(lastchar != '\n')
        ++newlines;
      done = TRUE;
    }
    else
        symb++;
    lastchar = c;
  }
  int Total = blanks + tabs + newlines + i;
  printf("Blanks: %d\nTabs: %d\nLines: %d\nSymbols: %d\nTotal: %d\n", blanks, tabs, newlines, symb, Total);
  return 0;
}

