/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:52:17 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/22 01:59:03 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strnstr(const char *big, const char *little, int len)
{
	int		i;
	int		j;
	size_t	yes;

	i = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (big && big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			yes = 1;
			while (little[j])
			{
				if ((big[i + j] != little[j]) || ((i + j) >= len))
					yes = 0;
				j++;
			}
			if (yes == 1)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	size_t	size;

	size = len_nbr(n);
	nbr = malloc(sizeof(char) * (size + 1));
	if (!nbr)
		return (NULL);
	return (fill_nbr(nbr, size, n));
}

char	*fill_nbr(char *nbr, size_t size, int n)
{
	nbr[size] = '\0';
	if (n == -2147483648)
	{
		nbr[0] = '-';
		nbr[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}
	if (n == 0)
		nbr[size - 1] = 48;
	else
	{
		while (n >= 1)
		{
			size--;
			nbr[size] = n % 10 + 48;
			n = n / 10;
		}
	}
	return (nbr);
}

size_t	len_nbr(int n)
{
	size_t	size;

	size = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while ((n / 10) >= 1)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*lib_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		join[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		join[i] = s2[i - len1];
		i++;
	}
	join[i] = '\0';
	return (join);
}
