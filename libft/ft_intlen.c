/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:05:05 by tketonen          #+#    #+#             */
/*   Updated: 2021/12/28 18:44:06 by tketonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long long int n)
{
	static int	len = 0;

	if (n < 0)
	{
		n = (n * -1);
		len++;
		return (ft_intlen(n));
	}
	while (n >= 10)
	{
		len++;
		n = (n / 10);
	}
	len++;
	return (len);
}
