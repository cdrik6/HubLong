/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:36:17 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/21 18:25:26 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *stash, char *buff)
{
	char	*join;
	int		i;
	int		j;

	if (stash == NULL || buff == NULL)
		return (free(stash), NULL);
	join = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buff) + 1));
	if (!join)
		return (free(stash), NULL);
	i = 0;
	j = 0;
	while (stash[i])
	{
		join[i] = stash[i];
		i++;
	}
	while (buff[j])
	{
		join[i + j] = buff[j];
		j++;
	}
	join[i + j] = '\0';
	free(stash);
	return (join);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*sub;
	int		i;
	int		size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		size = 0;
	else if (start + len > ft_strlen(s))
		size = ft_strlen(s) - start;
	else
		size = len;
	i = start;
	sub = malloc(sizeof(char) * (size + 1));
	if (!sub)
		return (NULL);
	while (i < size + start)
	{
		sub[i - start] = s[i];
		i++;
	}
	sub[i - start] = '\0';
	return (sub);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (size != 0 && nmemb > ((size_t)(-1)) / size)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)str)[i] = 0;
		i++;
	}
	return (str);
}
