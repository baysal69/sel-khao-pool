/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:40:37 by sel-khao          #+#    #+#             */
/*   Updated: 2024/10/29 23:42:14 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (str + i);
		i++;
		j = 0;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
    char *str = "Hello, welcome to the world of C programming!";
    char *to_find = "welcome";

    // Perform the test
    char *result = ft_strstr(str, to_find);
	printf("Found substring: %s\n", result);
	char *result2 = strstr(str, to_find);
	printf("Found substring: %s\n", result2);
    return 0;
}*/
