/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:05:05 by tketonen          #+#    #+#             */
/*   Updated: 2021/11/22 17:24:06 by tketonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = (ft_strlen(needle));
	if (*needle == '\0')
		return ((char *)haystack);
	while (i <= len && haystack[i] != '\0')
	{
		if (ft_strncmp((char *)&haystack[i], needle, l) == 0)
		{
			if ((i + l) > len)
				return (NULL);
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
