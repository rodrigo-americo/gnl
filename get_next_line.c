/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:49:12 by rgregori          #+#    #+#             */
/*   Updated: 2025/08/08 15:13:20 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_found_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

static char	*ft_get_line_from_stash(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	new_line = ft_substr(str, 0, i);
	return (new_line);
}

static char	*ft_update_stash(char *str, char *line)
{
	char	*temp_stash;

	temp_stash = ft_substr(str, ft_strlen(line),
			ft_strlen(str) - ft_strlen(line));
	free(str);
	return (temp_stash);
}

static int	read_and_update_stash(char **stash, int fd, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_found_newline(*stash) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			if (*stash)
			{
				free(*stash);
				*stash = NULL;
			}
			return (-1);
		}
		buffer[bytes_read] = '\0';
		if (!*stash)
			*stash = ft_strdup("");
		temp = ft_strjoin(*stash, buffer);
		free(*stash);
		*stash = temp;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (read_and_update_stash(&stash, fd, buffer) == -1)
		return (NULL);
	if (!stash || stash[0] == '\0')
	{
		free(buffer);
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_get_line_from_stash(stash);
	stash = ft_update_stash(stash, line);
	free(buffer);
	return (line);
}
