/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 10:49:09 by rgregori          #+#    #+#             */
/*   Updated: 2025/07/25 14:38:47 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s[count])
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j++;
	}
	s3[i + j] = '\0';
	return (s3);
}

char	*ft_strdup(const char *src)
{
	char	*cop;
	int		i;

	cop = malloc(ft_strlen(src) + 1);
	if (!cop)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cop[i] = src[i];
		i++;
	}
	cop[i] = '\0';
	return (cop);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	if (!dest || !src)
		return (0);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		s_len;
	size_t		alloc_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	alloc_len = s_len - start;
	if (alloc_len > len)
		alloc_len = len;
	sub = malloc(alloc_len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, alloc_len + 1);
	return (sub);
}
