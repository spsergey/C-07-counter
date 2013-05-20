#include <iostream>
#include <stdio.h>

int main()
{
    int i = 0;
    while ( getchar()!=EOF)
    {
        i++;
    }
    printf("%d\n", i-1);


    return 1;
}

