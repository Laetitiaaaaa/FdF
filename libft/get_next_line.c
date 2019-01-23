/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llejeune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:12:53 by llejeune          #+#    #+#             */
/*   Updated: 2019/01/23 15:49:34 by llejeune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sizeline(char *tmp)
{
	int	i;
	int size;

	i = 0;
	size = 0;
	while (tmp[i++] != '\n')
		size++;
	return (size);
}

static int		line_no_eof(char **tmp, char **line)
{
	char	*str;

	if ((*tmp)[0] == '\n')
		*line = ft_strnew(0);
	else
		*line = ft_strsub(*tmp, 0, sizeline(*tmp));
	str = *tmp;
	*tmp = ft_strdup(ft_strchr(str, '\n') + 1);
	free(str);
	return (1);
}

static int		eof(char **tmp, char **line)
{
	char	*str;

	if (ft_strlen(*tmp) == 0)
	{
		*line = NULL;
		free(*tmp);
		*tmp = NULL;
		return (0);
	}
	if (ft_strchr(*tmp, '\n') == NULL)
	{
		*line = ft_strdup(*tmp);
		*tmp = ft_strnew(0);
	}
	else
	{
		*line = ft_strsub(*tmp, 0, sizeline(*tmp));
		str = *tmp;
		*tmp = ft_strdup(ft_strchr(str, '\n') + 1);
		free(str);
	}
	return (1);
}

static void		lecture(char **buf, char **tmp)
{
	char	*str;

	str = *tmp;
	*tmp = ft_strjoin(str, *buf);
	free(str);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	int			res;
	char		*buf;
	static char	*tmp = NULL;

	if ((!(buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			|| fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	ret = BUFF_SIZE;
	if (tmp == NULL)
		tmp = ft_strnew(0);
	while (ft_strchr(tmp, '\n') == NULL && ret == BUFF_SIZE)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		lecture(&buf, &tmp);
	}
	if (ft_strchr(tmp, '\n') != NULL && ret == BUFF_SIZE)
		res = line_no_eof(&tmp, line);
	if (ret < BUFF_SIZE)
		res = eof(&tmp, line);
	free(buf);
	return (res);
}
