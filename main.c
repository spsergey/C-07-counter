#include <iostream>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
    int blanks, tabs, newlines;
    int c;
    bool done = FALSE;
    int lastchar = 0;
    int i = 0;
    char ch;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    ch = getopt (argc, argv, "ns");

    while (done == FALSE)
    {
        switch (c = getchar())
        {
        case ' ':
            ++blanks;
            break;

        case '\t':
            ++tabs;
            break;

        case '\n':
            ++newlines;
            break;

        case EOF:
        {
            if(lastchar != '\n')
                ++newlines;
            done = TRUE;
        }
            break;

        default:
            i++;
        }
        lastchar = c;
    }
    if (ch == -1)
        printf("Total number of symbols: %d\n", blanks + tabs + newlines + i);
    switch (ch) {
    case 'n':
        printf ("Number of symbols without 'Newline' symbol: %d\n", blanks + tabs + i);
        break;
    case 's':
        printf ("Number of symbols without spaces and 'Tab' symbol: %d\n", newlines + i);
        break;
    case '?':
    default:
        printf ("Usage: %s [-n] [-s].\n", argv[0]);
    }
    return 0;
}
