#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int ac, char **av)
{
    int i = 0;
    int j;
    int a = 0;

    j = 0;
    if (ac == 3)
    {
        while (av[1][i]  != '\0')
        {
            j = 0;
            while(av[2][i] != '\0')
            {
                if(av[1][i] == av[2][j])
                {
                    write(1, &av[2][i], 1);
                    a= j;
                    while(av[2][a] != '\0')
                    {
                        if(av[2][a] == av[1][i])
                            av[2][a] = 127;
                        a++;
                    }
                    j++;
                }                
                i++;        
            }
            i++;  
        }
        write (1, "\n", 1);
    }
    else
    write (1, "\n", 1);

}