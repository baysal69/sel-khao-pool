/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sara <sara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:54:05 by sara              #+#    #+#             */
/*   Updated: 2025/03/13 01:20:51 by sara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2)
    {
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
            {
                if (argv[1][i] == 'z')
                    argv[1][i] = 'a';
                else
                    argv[1][i] += 1;
                write (1, &argv[1][i], 1);
            }
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                if (argv[1][i] == 'Z')
                    argv[1][i] = 'A';
                else
                    argv[1][i] += 1;
                write (1, &argv[1][i], 1);
            }
            else   
                write (1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}