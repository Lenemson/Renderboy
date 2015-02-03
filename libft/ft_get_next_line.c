/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibanez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:08:19 by jibanez           #+#    #+#             */
/*   Updated: 2015/01/27 13:11:17 by jibanez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int		check_buffer(char **line, char *sbuffer)
{
	char	*to_free;
	char	*tmp;
	char	*nl;
	int		len;

	len = ft_strlen(sbuffer);
	if (len == 0)
		return (0);
	if ((tmp = ft_strnew(len)) == NULL)
		return (-1);
	ft_memccpy(tmp, sbuffer, '\n', len);
	nl = ft_strchr(tmp, '\n');
	if (nl)
		*nl = '\0';
	to_free = *line;
	*line = ft_strjoin(*line, tmp);
	ft_strdel(&tmp);
	ft_strdel(&to_free);
	if ((tmp = ft_strchr(sbuffer, '\n')))
	{
		ft_strcpy(sbuffer, tmp + 1);
		return (1);
	}
	ft_bzero(sbuffer, BUFF_SIZE);
	return (0);
}

static int		read_file(int const fd, char **line, char *sbuffer)
{
	int		ret;
	int		check;

	while ((ret = read(fd, sbuffer, BUFF_SIZE)) > 0)
	{
		sbuffer[ret] = '\0';
		check = check_buffer(line, sbuffer);
		if (check == -1)
			return (-1);
		else if (check == 1)
			return (1);
	}
	if (ret == -1)
		return (-1);
	else if (ft_strlen(*line))
		return (1);
	return (0);
}

int				ft_get_next_line(int const fd, char **line)
{
	static char		sbuffer[BUFF_SIZE + 1];
	int				ret;

	sbuffer[BUFF_SIZE] = '\0';
	if (BUFF_SIZE < 1 || !line || fd < 0)
		return (-1);
	if ((*line = ft_strnew(1)) == NULL)
		return (-1);
	ret = check_buffer(line, sbuffer);
	if (ret == 1)
		return (1);
	else if (ret == -1)
		return (-1);
	ret = read_file(fd, line, sbuffer);
	return (ret);
}
