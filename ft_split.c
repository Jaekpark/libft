/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekpark <jaekpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:27:34 by jaekpark          #+#    #+#             */
/*   Updated: 2020/10/19 13:11:12 by jaekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			word_count(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int			*word_size(char const *s, char c)
{
	int		*arr;
	int		size;
	int		i;
	int		j;

	if (!(arr = malloc(sizeof(int) * word_count(s, c))))
		return (NULL);
	size = 0;
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				arr[j] = size;
				size = 0;
				j++;
			}
		}
		i++;
	}
	return (arr);
}

void		mem_allocate(char **dest, int *size, int count)
{
	int		i;

	i = 0;
	dest[count] = NULL;
	while (count)
	{
		dest[i] = malloc(sizeof(char) * size[i] + 1);
		i++;
		count--;
	}
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		*size;
	char	**dest;

	if (!s || !(dest = (char **)malloc(sizeof(char *) * word_count(s, c) + 1)))
		return (NULL);
	size = word_size(s, c);
	mem_allocate(dest, size, word_count(s, c));
	i = -1;
	j = 0;
	k = 0;
	while (s[++i])
		if (s[i] != c)
		{
			dest[j][k++] = s[i];
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				dest[j++][k] = '\0';
				k = 0;
			}
		}
	free(size);
	return (dest);
}
