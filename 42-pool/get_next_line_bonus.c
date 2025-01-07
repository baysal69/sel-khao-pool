/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:50:33 by sel-khao          #+#    #+#             */
/*   Updated: 2025/01/07 17:15:56 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (freed(&line[fd]));
	utils.buffer = malloc(BUFFER_SIZE + 1);
	if (!utils.buffer)
		return (freed(&line[fd]));
	while (utils.readed == BUFFER_SIZE && utils.trunc == -1)
	{
		utils.readed = read(fd, utils.buffer, BUFFER_SIZE);
		if (utils.readed < 0)
		{
			freed(&utils.buffer);
			return (freed(&line[fd]));			
		}
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

/* #include <fcntl.h>
#include <stdio.h>
int main (void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	char *line1;
	char *line2;
	char *line3;

	fd1 = open("hi.txt", O_RDONLY);
	fd2 = open("hey.txt", O_RDONLY);
	fd3 = open("hope.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("errorino :c");
		return (1);
	}
	while (1)
	{
		if (line1 = get_next_line(fd1))
		{
			printf ("line1: [%s]", line1);
			free(line1);			
		}
		if (line2 = get_next_line(fd2))
		{
			printf ("line2: [%s]", line2);
			free(line2);			
		}
		if (line3 = get_next_line(fd3))
		{
			printf ("line3: [%s]", line3);
			free(line3);			
		}
		if (!line1 && !line2 && !line3)
			break;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return(0);
} */