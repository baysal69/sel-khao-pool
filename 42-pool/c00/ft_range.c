int ft_abs(int start, int end)
{
    int sum;

    if (end < start)
        sum = -(end - start);
    else if (start < end)
        sum = -(start - end);
    return (sum);
}
int     *ft_range(int start, int end)
{
    int *list;
    int len;
    int i = 0;

    len = ft_abs(start, end);
    list = malloc (len * sizeof(int));

    if(end <= start)
    {
        while (end <= start)
        {
            list[i] = end++;
            i++;
        }
    }
    else
    {
        i = 0;
        while (start <= end)
        {
            list[i] = start++;
            i++;
        }
    }
    return (list);
}
