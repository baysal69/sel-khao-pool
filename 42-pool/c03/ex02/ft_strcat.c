/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:40:43 by sel-khao          #+#    #+#             */
/*   Updated: 2024/10/29 20:41:53 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*#include <stdio.h>
int main()
{
    char dest1[50] = "Hello, "; // Ensure enough space
    char src1[] = "world!";
    
    ft_strcat(dest1, src1);
    printf("ft_strcat: %s\n", dest1); // Output: Hello, world!

    // Example with standard strcat
    char dest2[50] = "Hello, "; // Ensure enough space
    char src2[] = "world!";
    
    strcat(dest2, src2);
    printf("strcat: %s\n", dest2); // Output: Hello, world!

    return 0;
}*/
