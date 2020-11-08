/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:27:50 by jaekpark          #+#    #+#             */
/*   Updated: 2020/11/08 17:45:09 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (ft_strlen(src) + size);
	count = size - ft_strlen(dst) - 1;
	while (*src && count--)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
