/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:52:27 by sel-khao          #+#    #+#             */
/*   Updated: 2024/12/23 23:49:14 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_utils
{
	ssize_t	readed;
	char	*next_line;
	char	*buffer;
	char	*left_over;
	int		trunc;
}					t_utils;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strlcpy(char *dst, char *src, int size);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
int		ft_trunc(char *str);

#endif