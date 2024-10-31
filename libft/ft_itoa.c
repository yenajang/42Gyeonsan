/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenjang <yenjang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:23:55 by yenjang           #+#    #+#             */
/*   Updated: 2024/10/12 14:05:22 by yenjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*if_negative(long long n)
{
	int			i;
	long long	n2;
	char		*str;

	n2 = (long)n * -1;
	n *= -1;
	i = 1;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	str = (char *)malloc(sizeof(char) * (i + 2));
	str[0] = '-';
	str[i + 1] = '\0';
	while (i)
	{
		str[i] = n2 % 10 + '0';
		n2 /= 10;
		i--;
	}
	return (str);
}

char	*if_plus(int n)
{
	int		i;
	int		n2;
	char	*str;

	n2 = n;
	i = 1;
	while (n >= 10)
	{
		i++;
		n = n / 10;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = n2 % 10 + '0';
		n2 /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		return (if_negative(n));
	}
	else
		return (if_plus(n));
}
