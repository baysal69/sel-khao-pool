/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:52:27 by sel-khao          #+#    #+#             */
/*   Updated: 2024/12/23 23:49:14 by sel-khao         ###   ########.fr       */
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
	static char	*line[OPEN_MAX];
	t_utils		utils;

	initial(&utils);
	if (BUFFER_SIZE <= 0 || fd < 0 || !(utils.buffer = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	while (utils.readed == BUFFER_SIZE && utils.trunc == -1)
	{
		utils.readed = read(fd, utils.buffer, BUFFER_SIZE);
		utils.buffer[utils.readed] = '\0';
		utils.left_over = line[fd];
		line[fd] = ft_strjoin(line[fd], utils.buffer);
		freed(&utils.left_over);
		utils.trunc = ft_trunc(line[fd]);
	}
	freed(&utils.buffer);
	if (utils.trunc == -1)
		return (utils.left_over = last_line(&line[fd]));
	else
		utils.next_line = trunc_line(&line[fd], utils.trunc);
	return (utils.next_line);
}

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
}