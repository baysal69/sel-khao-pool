/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:19:49 by sel-khao          #+#    #+#             */
/*   Updated: 2024/11/05 14:13:20 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
	{
		return (0);
	}
	i = 1;
	while (i * i < nb)
		i++;
	if (i * i == nb)
	{
		return (i);
	}
	return (0);
}
/*#include <stdio.h>
int main()
{
	printf("%d\n", ft_sqrt(144));
}*/