/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lben-adi <lben-adi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:27:30 by lben-adi          #+#    #+#             */
/*   Updated: 2024/07/15 20:38:48 by lben-adi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	make_stash(char *line, char *buff)
{
	size_t	index;

	index = 0;
	while (line[index])
	{
		buff[index] = line[index];
		index++;
	}
	buff[index] = '\0';
}

char	*make_line(char *line, char *buff)
{
	char	*final_line;
	size_t	final_line_len;
	size_t	index;

	final_line_len = ft_strlen_gnl(line, 1) + 1;
	index = 0;
	final_line = (char *)malloc((final_line_len * sizeof(char)) + 1);
	if (!final_line)
		return (free(line), NULL);
	while (final_line_len)
	{
		final_line[index] = *line++;
		index++;
		final_line_len--;
	}
	final_line[index] = '\0';
	make_stash(line, buff);
	free((line - index));
	return (final_line);
}

char	*stock_line(char *line, char *buff, ssize_t *byte_len, int fd)
{
	char	*temp_line;

	if (buff[0])
	{
		temp_line = line;
		line = ft_strjoin_gnl((const char *)line, (const char *)buff, temp_line);
		if (!line)
			return (NULL);
	}
	while (*byte_len != 0)
	{
		if (ft_strchr(line, '\n'))
			return (line = make_line(line, buff));
		*byte_len = read(fd, buff, BUFFER_SIZE);
		if (*byte_len == -1)
			return (free(line), NULL);
		buff[*byte_len] = '\0';
		temp_line = line;
		line = ft_strjoin_gnl((const char *)line, (const char *)buff, temp_line);
		if (!line)
			return (NULL);
		if (ft_strchr(buff, '\n') || *byte_len == 0)
			return (line = make_line(line, buff));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		byte_len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	byte_len = 1;
	line = NULL;
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	temp = stock_line(line, buff, &byte_len, fd);
	if (!temp)
	{
		*buff = 0;
		return (NULL);
	}
	if (byte_len == 0 && temp[0] == '\0')
		return (free(temp), NULL);
	return (temp);
}
