/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:34:18 by sel-khao          #+#    #+#             */
/*   Updated: 2024/10/20 18:17:47 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recall(int a, int b)
{
	char	c;

	c = (a / 10) + '0';
	write(1, &c, 1);
	c = (a % 10) + '0';
	write(1, &c, 1);
	write(1, " ", 1);
	c = (b / 10) + '0';
	write(1, &c, 1);
	c = (b % 10) + '0';
	write(1, &c, 1);
	if (a != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			{
				recall(a, b);
			}
			b++;
		}
		a++;
	}
}

/*int main(void)
{
	ft_print_comb2();
	return 0;
}*/
