/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:09:05 by sel-khao          #+#    #+#             */
/*   Updated: 2025/04/01 21:58:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>


void	signal_handler(int signum, siginfo_t *info, void *context);

int main()
{
    struct sigaction	sa;

    printf("PID: %d\n", getpid());
    sa = (struct sigaction){0};
    while (1)
    { 
        sa.sa_sigaction = &signal_handler;
	    sa.sa_flags = SA_SIGINFO;
	    sigaction(SIGUSR1, &sa, NULL);
	    sigaction(SIGUSR2, &sa, NULL); 
    }
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
    (void)context;
    (void)info;
	static unsigned char	bits;
	static int				len;

	if (signum == SIGUSR1)
		bits = (bits << 1) | 0b00000001;
	else if (signum == SIGUSR2)
		bits = (bits << 1);
	len++;
	if (len == 8)
	{
		write(1, &bits, 1);
		bits = 0;
		len = 0;
	}
}