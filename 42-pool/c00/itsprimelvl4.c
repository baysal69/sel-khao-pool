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