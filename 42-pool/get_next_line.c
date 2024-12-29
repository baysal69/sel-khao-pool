/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:51:24 by sel-khao          #+#    #+#             */
/*   Updated: 2024/12/23 23:52:25 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*freed(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*last_line(char **line)
{
	char	*tmp;

	tmp = ft_strdup(*line);
	freed(line);
	return (tmp);
}

static char	*trunc_line(char **line, int trunc)
{
	char	*next_line;
	char	*temp;

	next_line = malloc(trunc + 2);
	if (!next_line)
		return (freed(line));
	ft_strlcpy(next_line, *line, trunc + 2);
	temp = *line;
	*line = ft_strdup((*line) + trunc + 1);
	freed(&temp);
	return (next_line);
}

static void	initial(t_utils *utils)
{
	utils->next_line = NULL;
	utils->buffer = NULL;
	utils->left_over = NULL;
	utils->readed = BUFFER_SIZE;
	utils->trunc = -1;
}

char	*get_next_line(int fd)
{
	static char	*line;
	t_utils		utils;

	initial(&utils);
	if (BUFFER_SIZE <= 0 || fd < 0 || !(utils.buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	while (utils.readed == BUFFER_SIZE && utils.trunc == -1)
	{//loops continues readin until we read less than BF(end of file or line) OR until we find \n
		utils.readed = read(fd, utils.buffer, BUFFER_SIZE);
		utils.buffer[utils.readed] = '\0';
//ensures buffer is null termineted
		utils.left_over = line;
		line = ft_strjoin(line, utils.buffer);
		freed(&utils.left_over);
		utils.trunc = ft_trunc(line);
	}
	freed(&utils.buffer);
	if (utils.trunc == -1)
		return (utils.left_over = last_line(&line));
	else
		utils.next_line = trunc_line(&line, utils.trunc);
	return (utils.next_line);
}
/*#include <fcntl.h>
#include <stdio.h>
int main (void)
{
	int	fd;
	char *line;

	fd = open("hello.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("%s\n", "got unlucky :c");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%s]", line);
		free(line);
	}
	close(fd);
	return (0);
}*/