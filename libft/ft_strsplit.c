/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:15:55 by tketonen          #+#    #+#             */
/*   Updated: 2021/12/02 17:24:06 by tketonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_newarray(char const *s, char c)
{
	int		i;

	i = 0;
	if (*s != c && *s != 0)
	{
		i++;
		s++;
	}
	while (*s != 0)
	{
		if (*s != c && s[-1] == c)
			i++;
		s++;
	}
	return (i + 1);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * ft_newarray(s, c));
	if (!result)
		return (NULL);
	while (*s != 0)
	{
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i)
		{
			result[j++] = ft_strncpy(ft_strnew(i), s, i);
			s = &s[i];
		}
		else
			s++;
	}
	result[j] = NULL;
	return (result);
}
