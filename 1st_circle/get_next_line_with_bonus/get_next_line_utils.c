/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:55:17 by kuzyilma          #+#    #+#             */
/*   Updated: 2024/11/24 10:02:59 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s != NULL && s[len] != '\0')
		len++;
	return (len);
}

static void	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return ;
	if (dstsize != 0)
	{
		while (src [i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*ans;

	size = ft_strlen(s);
	if (start >= size)
	{
		ans = (char *)malloc(sizeof(char));
		if (!ans)
			return (NULL);
		ans[0] = '\0';
	}
	else
	{
		size = size - start;
		if (len < size)
			size = len;
		ans = (char *)malloc(sizeof(char) * (size + 1));
		if (!ans)
			return (NULL);
		ft_strlcpy(ans, s + start, size + 1);
	}
	return (ans);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ans;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ans = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ans)
		return (NULL);
	ft_strlcpy(ans, s1, s1_len + 1);
	ft_strlcpy(ans + s1_len, s2, s2_len + 1);
	return (ans);
}
