/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 22:44:40 by jaekpark          #+#    #+#             */
/*   Updated: 2020/11/08 17:32:15 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t num)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	while (num--)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}
