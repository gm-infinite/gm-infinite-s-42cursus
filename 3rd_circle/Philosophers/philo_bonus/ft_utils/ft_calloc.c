/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:46:45 by kuzyilma          #+#    #+#             */
/*   Updated: 2025/01/28 12:35:31 by kuzyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;

	ans = (void *)malloc(count * size);
	if (!ans)
		return (0);
	ft_bzero(ans, count * size);
	return (ans);
}
