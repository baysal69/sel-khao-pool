/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-khao <sel-khao <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:52:27 by sel-khao          #+#    #+#             */
/*   Updated: 2024/12/23 23:49:14 by sel-khao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*freed(char **str)
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
		ft_reading(&utils, fd, &line[fd]);
	}
	freed(&utils.buffer);
	if (utils.trunc == -1)
		return (utils.left_over = last_line(&line[fd]));
	else
		utils.next_line = trunc_line(&line[fd], utils.trunc);
	return (utils.next_line);
}
#include <fcntl.h>
int main (void)
{
	int	fd1;
	int fd2;
	char *line;

	fd1 = open("hope.txt", O_RDONLY);
	fd2 = open("hello.txt", O_RDONLY);
	//fd3 = open("hello.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("not workin");
		return (1);
	}
	printf("FIRST ONE:\n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("[%s]", line);
		free(line);
	}
	printf("SECOND ONE:\n");
	while ((line = get_next_line(fd2)) != NULL)
	{
	printf("[%s]", line);
	free(line);
	}
	//printf("THIRD ONE:\n");
//	while ((line = get_next_line(fd3)) != NULL)
//	{
//		printf("[%s]", line);
//		free(line);
//	}
	close(fd1);
	close(fd2);
//	close(fd3);
	return(0);
}