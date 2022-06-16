/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:06:47 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/30 22:24:15 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_intstr(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_intstr(n / 10, str, i);
		ft_intstr(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nb;

	nb = n;
	str = ft_memalloc(ft_intlen(nb) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		str[i++] = '-';
		nb = nb * -1;
	}
	ft_intstr(nb, str, &i);
	str[i] = '\0';
	return (str);
}
