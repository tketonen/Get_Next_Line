/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:05:05 by tketonen          #+#    #+#             */
/*   Updated: 2021/11/27 17:24:06 by tketonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	size_t	len;

	if (!s)
		return (NULL);
	i = ft_trimstart(s);
	j = ft_trimend(s);
	if (s[i] == '\0')
		return (ft_strnew(0));
	len = (j - i) + 1;
	return (ft_strsub(s, i, len));
}
