/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:19:00 by sel-khao          #+#    #+#             */
/*   Updated: 2024/10/27 23:32:26 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/*#include <stdio.h>
int	main()
{
	int a;
	int b;
	char x[] = "resto";
	a = 30;
	b = 10;
	ft_ultimate_div_mod(&a, &b);
	printf("risultato: %d, %s: %d", a, x, b);
    return (0);
}*/
