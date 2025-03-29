#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int sign;
    int res;
    int i;
    int ok;

    ok = 0;
    i = 0;
    res = 0;
    sign = 1;
    while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            ok = str[i] - 48;
        else if (str[i] >= 'a' && str[i] <= 'f')
            ok = str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            ok = str[i] - 'A' + 10;
        else
            break ;
        res = res * str_base + ok;
        i++;
    }
    return (res * sign);
}