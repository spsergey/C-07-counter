#include <counter.h>

int main(int argc, char **argv)
{
    int option_index = 0;
    int ch;
    bool done = false;
    int count [3];

    static struct option long_options[] =
    {
        {"help",     no_argument,       0, 'h'},
        {"no-newline",     no_argument,       0, 'n'},
        {"no-spaces",     no_argument,       0, 's'},
        {0, 0, 0, 0}
    };

    while ((ch = getopt_long (argc, argv, "nsh", long_options, &option_index)) != -1)
    {
        if (ch == 'h')
        {
            printf ("Use [-n or --no-newline] to count symbols without 'Newline' symbol\nUse [-s or --no-spaces] to count symbols without spaces and 'Tab' symbols\n");
            return 0;
        }
        if (done == false)
        {
            counter(count);
            done = true;
        }
        switch (ch) {
        case 'n':
	    count[0] = count[0] - count[1];
            break;
        case 's':
	    count[0] = count[0] - count[2];
            break;
        case '?':
        default:
            printf ("Usage: %s [-n or --no-newline] [-s or --no-spaces]\n", argv[0]);
        }
    }
    if (done == false)
        counter(count);  
    printf("Number of symbols: %d\n", count[0]);
    return 0;
}

