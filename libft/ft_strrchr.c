/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenjang <yenjang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:20:45 by yenjang           #+#    #+#             */
/*   Updated: 2024/10/11 16:01:13 by yenjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*p;
	int			i;

	i = 0;
	p = NULL;
	if (c == '\0')
	{
		while (*str)
		{
			str++;
		}
		return ((char *)str);
	}
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			p = &str[i];
		}
		i++;
	}
	return ((char *)p);
}
