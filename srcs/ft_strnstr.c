/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:52:17 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/10 22:40:14 by caguillo         ###   ########.fr       */
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
