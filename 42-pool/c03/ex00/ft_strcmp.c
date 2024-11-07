/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:36:50 by sel-khao          #+#    #+#             */
/*   Updated: 2024/10/30 20:16:08 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>
int main() {
  char str1[] = "Sara", str2[] = "sara";
  int result;
  // comparing strings str1 and str2, it should give -32
  //because its the ascii difference from S to s
  result = ft_strcmp(str1, str2);
  printf("ft_strcmp(str1, str2) = %d\n", result);
  return 0;
}*/