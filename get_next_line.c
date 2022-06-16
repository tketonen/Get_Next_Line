/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tketonen <tketonen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:32 by tketonen          #+#    #+#             */
/*   Updated: 2022/01/11 23:24:45 by tketonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	addline(char **str, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_strsub(*str, 0, len);
		temp = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	checkoutput(char **str, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && str[fd] == NULL)
		return (0);
	else
		return (addline(&str[fd], line));
}

static int	readbuffer(const int fd, char **line, char **str)
{
	int		ret;
	char	*temp;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	while (ret > 0)
	{
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n') != NULL)
			break ;
		ret = read(fd, buff, BUFF_SIZE);
		buff[ret] = '\0';
	}
	free(buff);
	return (checkoutput(str, line, ret, fd));
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[FD_SIZE];

	if (fd < 0 || line == NULL || fd > FD_SIZE)
		return (-1);
	if (str[fd] != NULL)
	{
		if (ft_strchr(str[fd], '\n') != NULL)
			return (addline(&str[fd], line));
	}
	return (readbuffer(fd, line, str));
}
