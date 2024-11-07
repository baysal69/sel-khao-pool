/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:45:35 by sel-khao          #+#    #+#             */
/*   Updated: 2024/11/06 00:16:52 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
	{
		return (0);
	}
	i = 2;
	while (i <= (nb / 2))
	{
		if (nb % i == 0)
		{
			return (0);
		}
		else
			i++;
	}
	return (1);
}
/*#include <stdio.h>
int main()
{
    printf("%d -> %d\n", 3, ft_is_prime(3));
    printf("%d -> %d\n", 1, ft_is_prime(1));
    printf("%d -> %d\n", 4, ft_is_prime(4));
    printf("%d -> %d\n", 5, ft_is_prime(5));
}*/
