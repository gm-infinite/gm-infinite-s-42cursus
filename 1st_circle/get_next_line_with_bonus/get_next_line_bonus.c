/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:58:17 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/11/24 10:02:26 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_char_calloc(size_t count, size_t size)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = (char *)malloc(count * size);
	if (!ans)
		return (0);
	while (i < count * size)
	{
		ans[i] = 0;
		i++;
	}
	return (ans);
}

static char	*update_saved(char *saved)
{
	char	*temp;
	int		i;

	i = 0;
	while (saved[i] != '\n' && saved[i])
		i++;
	if (saved[i] == '\0')
	{
		free(saved);
		return (NULL);
	}
	temp = ft_substr(saved, i + 1, ft_strlen(saved));
	free(saved);
	return (temp);
}

static char	*get_the_line(char *saved)
{
	int		i;

	i = 0;
	while (saved[i] != '\n' && saved[i])
		i++;
	return (ft_substr(saved, 0, i + (saved[i] == '\n')));
}

static char	*get_file_text(char *saved, int fd, int *eof)
{
	char	*buf;
	char	*temp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	while (!ft_strchr(saved, '\n'))
	{
		*eof = read(fd, buf, BUFFER_SIZE);
		if (*eof <= 0)
		{
			free(buf);
			return (saved);
		}
		buf[*eof] = '\0';
		temp = saved;
		saved = ft_strjoin(saved, buf);
		if (temp)
			free(temp);
	}
	free(buf);
	return (saved);
}

char	*get_next_line(int fd)
{
	static	char	*(saved[8192]);
	char			*line;
	int				eof;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(saved[fd]))
		saved[fd] = ft_char_calloc(1, sizeof(char));
	eof = 0;
	saved[fd] = get_file_text(saved[fd], fd, &eof);
	if (!(saved[fd]) || *(saved[fd]) == '\0')
	{
		free(saved[fd]);
		saved[fd] = NULL;
		return (NULL);
	}
	if (eof <= 0 || ft_strchr(saved[fd], '\n'))
	{
		line = get_the_line(saved[fd]);
		saved[fd] = update_saved(saved[fd]);
		return (line);
	}
	return (NULL);
}