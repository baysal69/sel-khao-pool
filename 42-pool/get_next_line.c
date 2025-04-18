/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:51:24 by sel-khao          #+#    #+#             */
/*   Updated: 2025/01/07 17:59:41 by sel-khao         ###   ########.fr       */
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
	char	*temp;

	temp = ft_strdup(*line);
	freed(line);
	return (temp);
}

static char	*trunc_line(char **line, int trunc)
{
	char	*next_line;
	char	*temp;

	next_line = ft_strdup(*line);
	if (!next_line)
		return (freed(line));
	next_line[trunc + 1] = '\0';
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
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (freed(&line));
	utils.buffer = malloc(BUFFER_SIZE + 1);
	if (!utils.buffer)
		return (freed(&line));
	while (utils.readed == BUFFER_SIZE && utils.trunc == -1)
	{
		utils.readed = read(fd, utils.buffer, BUFFER_SIZE);
		if (utils.readed < 0)
		{
			freed(&utils.buffer);
			return (freed(&line));			
		}
		utils.buffer[utils.readed] = '\0';
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

/* #include <stdio.h>
#include <fcntl.h>
int main (void)
{
	int	fd;
	char *line;

	fd = open("hi.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("%s\n", "got unlucky :c");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("_%s", line);
		free(line);
	}
	close(fd);
	return (0);
} */