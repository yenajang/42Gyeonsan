/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenjang <yenjang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:53:48 by yenjang           #+#    #+#             */
/*   Updated: 2024/10/18 13:34:11 by yenjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);

int	find_charset(char c, const char *charset)
{
	while (*charset != '\0')
	{
		if (c == *charset)
			return (1);
		else
			charset++;
	}
	return (0);
}

size_t	find_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && find_charset(s1[start], set))
		start++;
	return (start);
}

size_t	find_end(size_t start, char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (end > start && find_charset(s1[end], set))
		end--;
	return (end);
}

char	*make_str(size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = find_start(s1, set);
	end = find_end(start, s1, set);
	len = end - start + 1;
	str = make_str(len);
	end = 0;
	while (end < len)
	{
		str[end] = s1[start + end];
		end++;
	}
	str[end] = '\0';
	return (str);
}
