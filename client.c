/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:08:52 by sel-khao          #+#    #+#             */
/*   Updated: 2025/04/01 22:02:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') || i > 7)
			return (0);
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	return (res);
}

void	convert_signs(pid_t pid, char c)
{
	int	i;
    int bit;

	i = 0;
	while (i < 8)
	{
        bit = c << i & 0b10000000;
		if (bit == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	pid_t	pid;

	i = 0;
	
	if (argc != 3)
	{
		printf("not right number of arguments\n");
		exit(1);
	}
    pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
        printf("not valid PID\n");
		exit(1);
	}
	while (argv[2][i])
		convert_signs(pid, argv[2][i++]);
	return (0);
}
