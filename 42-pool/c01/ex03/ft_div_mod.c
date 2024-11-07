/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:18:46 by sel-khao          #+#    #+#             */
/*   Updated: 2024/10/24 23:34:21 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*#include <stdio.h>
int main()
{
	int a = 7;
	int b = 3;
	int div;
	int mod;

	ft_div_mod(a, b, &div, &mod);
	
	printf("%d\n", div);
	printf("%d\n", mod);

	return 0;
}*/
