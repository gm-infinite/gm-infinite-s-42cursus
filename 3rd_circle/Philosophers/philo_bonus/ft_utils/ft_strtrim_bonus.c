/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:12:48 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/02/05 16:29:19 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ans;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	ans = (char *)malloc(end - start + 1);
	if (!ans)
		return (NULL);
	ft_strlcpy(ans, s1 + start, end - start + 1);
	return (ans);
}
