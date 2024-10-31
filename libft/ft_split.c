/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenjang <yenjang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:02:10 by yenjang           #+#    #+#             */
/*   Updated: 2024/10/10 17:00:58 by yenjang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_char(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

int	count_word(char const *s, char c)
{
	int	word;
	int	flag;

	word = 0;
	flag = 1;
	while (*s)
	{
		if (!find_char(*s, c) && flag)
		{
			word++;
			flag = 0;
		}
		else if (find_char(*s, c))
			flag = 1;
		s++;
	}
	return (word);
}

char	*str_dup(char const *a, char const *b)
{
	int				i;
	int				len;
	char			*new_str;

	len = b - a;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		new_str[i] = a[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	**make_arr(int word_num)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (word_num + 1));
	if (!arr)
		return (NULL);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	int				word_num;
	int				i;
	char const		*a;
	char const		*b;

	word_num = count_word(s, c);
	arr = make_arr(word_num);
	i = 0;
	while (*s != '\0')
	{
		if (!(find_char(*s, c)))
		{
			a = s;
			while (!(find_char(*s, c)) && *s)
				s++;
			b = s;
			arr[i] = str_dup(a, b);
			i++;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
