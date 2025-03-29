#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ascii[255] = {0};
    int i = 1;
    int j = 0;

    if (argc == 3)
    {
        while (i < 3)
        {
            j = 0;
            while(argv[i][j])
            {
                if (ascii[(int)argv[i][j]] == 0)
                {
                    ascii[(int)argv[i][j]] = 1;
                    write(1, &argv[i][j], 1);
                }
                j++;
            }
            i++;
        }
    }
    write (1, "\n", 1);
}