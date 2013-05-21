#include <counter.h>

void counter (int mas[3])
{
    int blanks, tabs, newlines;
    int c;
    bool done = false;
    int lastchar = 0;
    int i = 0;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    while (done == false)
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
            done = true;
        }
            break;

        default:
            i++;
        }
        lastchar = c;
    }

    mas [0] = blanks + tabs + newlines + i;
    mas [1] = newlines;
    mas [2] = tabs + blanks;
}
