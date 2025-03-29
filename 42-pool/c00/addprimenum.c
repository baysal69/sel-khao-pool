void putnbr(int nbr)
{
    char str[10] = "0123456789";

    if (nbr > 9)
        putnbr(nbr / 10);
    write(1, &str[nbr % 10], 1);
}
int ft_atoi(char *num)
{
    int i = 0;
    int res = 0;

    while(num[i] >= '0' && num[i] <= '9')
    {
        res = res * 10 + (num[i] - 48);
        i++;
    }
    return(res);
}

int isprime(int nb)
{
    int i = 2;

    while(i <= (nb/2))
    {
        if (nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int i = 2;
    int nbr;
    int res;

    res = 0;
    if (argc == 2)
    {
        nbr = ft_atoi(argv[1]);
        if (nbr <= 0)
           return(write (1, "0\n", 2), 1);
        while (nbr >= i)
        {
            if (isprime(i) == 1)
                res += i;
            i++;
        }
        putnbr(res);
    }
    else
        write (1, "0", 1);
    write (1, "\n", 1);
}
