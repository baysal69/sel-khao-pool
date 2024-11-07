/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:01:50 by sel-khao          #+#    #+#             */
/*   Updated: 2024/10/16 17:36:33 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)

{
	write(1, "abcdefghijklmnopqrstuvwxyz", 26);
}
/*int main ()
{
	ft_print_alphabet();
}*/
