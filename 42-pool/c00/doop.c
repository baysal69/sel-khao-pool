#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int one;
    int two;
    int res;

    if (argc == 4)
    {
        one = atoi(argv[1]);
        two = atoi(argv[3]);
        if (argv[2][0] == '+')
            res = one + two;
        else if (argv[2][0] == '-')
            res = one - two;
        else if (argv[2][0] == '*')
            res = one * two;
        else if (argv[2][0] == '/')
            res = one / two;
        else if (argv[2][0] == '%')
            res = one % two;
        printf("%d\n", res);
    }
    else
        write (1, "\n", 1);
}