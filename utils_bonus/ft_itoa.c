/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <dozella@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:57:54 by dozella           #+#    #+#             */
/*   Updated: 2022/07/01 16:57:54 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	ft_fill_str(long n, char *str, size_t size)
{
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		size--;
		str[size] = n % 10 + 48;
		n = n / 10;
	}
}

static size_t	ft_get_size_of_nbr(long n)
{
	size_t	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = ft_get_size_of_nbr((long)n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str != NULL)
		ft_fill_str((long)n, str, size);
	return (str);
}
