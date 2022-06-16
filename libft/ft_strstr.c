/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:05:05 by tketonen          #+#    #+#             */
/*   Updated: 2021/11/22 17:24:06 by tketonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		i;
	char		*ptr;

	i = 0;
	ptr = NULL;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < (ft_strlen(haystack) + 1))
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			ptr = (char *) &haystack[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}
