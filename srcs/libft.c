/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:52:17 by caguillo          #+#    #+#             */
/*   Updated: 2024/02/16 19:53:03 by caguillo         ###   ########.fr       */
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
	char	c;

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
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
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
	size_t size;

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