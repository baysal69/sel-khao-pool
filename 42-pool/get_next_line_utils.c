/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:53:48 by sel-khao          #+#    #+#             */
/*   Updated: 2024/12/23 23:49:05 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s1[i] = s2[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		i++;
	}
	str[len] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		src[i] = dst[i];
		i++;
	}
	dst[i] = '\0';
	return(dst);
}

char	*ft_strdup(char *s)
{
	char	*str;

	if (!s || !(*s))
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	str = ft_strlcpy(str, s, ft_strlen(s) + 1);
	return (str);
}

int	ft_trunc(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
