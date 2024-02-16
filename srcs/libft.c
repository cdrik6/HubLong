/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:52:17 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/16 00:41:16 by caguillo         ###   ########.fr       */
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

void	ft_putnbr_fd(int n, int fd)
{
	char c;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		if (n < 10)
		{
			c = n + 48;
			write(fd, &c, 1);
		}
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;
	
	if (!s)
		return ;
	i = 0;	
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}