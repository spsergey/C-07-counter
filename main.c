#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int blanks, tabs, newlines;
    int c;
    bool done = false;
    int lastchar = 0;
    int i = 0;
    int ch;

    blanks = 0;
    tabs = 0;
    newlines = 0;

    static struct option long_options[] =
    {
        {"no-newline",     no_argument,       0, 'n'},
        {"no-spaces",     no_argument,       0, 's'},
        {0, 0, 0, 0}
    };

    int option_index = 0;

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
    while ((ch = getopt_long (argc, argv, "ns", long_options, &option_index)) != -1)
    {
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
            printf ("Usage: %s [-n or --no-newline] [-s or --no-spaces]\n", argv[0]);
        }
    }
    return 0;
}

