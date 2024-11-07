/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 20:24:21 by sel-khao          #+#    #+#             */
/*   Updated: 2024/11/05 14:11:44 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	while (nb % i != 0)
	{
		if (i > nb)
			break ;
		++i;
	}
	if (nb == i)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	while (1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}
/*#include <stdio.h>

int main()
{
    printf("%d\n", ft_find_next_prime(8));
}*/