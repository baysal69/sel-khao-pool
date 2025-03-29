/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:15:58 by sara              #+#    #+#             */
/*   Updated: 2025/03/12 23:23:01 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return (i);
}
int main(int argc, char *argv[])
{
    int i = 0;
    int len = ft_strlen(argv[1]);

    if (argc == 2)
    {
        while (len > i)
        {
            write(1, &argv[1][len - 1], 1);
            len--;
        }
    }
    write(1, "\n", 1);
    return 0;
}