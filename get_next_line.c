/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:38:49 by abettach          #+#    #+#             */
/*   Updated: 2021/02/17 12:16:39 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int		ft_store(char **new, int ret, char **line, int fd)
{
	char		*temp;
	int			i;

	i = 0;
	while (new[fd][i] && new[fd][i] != '\n')
		i++;
	*line = ft_substr(new[fd], 0, i);
	if (!new[fd][i])
	{
		temp = new[fd];
		new[fd] = NULL;
		free(temp);
		return (0);
	}
	else
	{
		temp = new[fd];
		new[fd] = ft_strdup((new[fd]) + i + 1);
		free(temp);
	}
	if (!new[fd] || !*line)
		return (-1);
	if (ret || (ret == 0 && new[fd] != NULL))
		return (1);
	return (-1);
}

int				get_next_line(int fd, char **line, t_mini *mini)
{
	char		*buff;
	static char	*rest[4864];
	char		*temp;
	int			ret;

	buff = NULL;
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0 ||
	!(buff = malloc(BUFFER_SIZE + 1)) || read(fd, buff, 0) < 0)
		return (-1);
	if (!rest[fd])
		if (!(rest[fd] = ft_strdup("")))
			return (-1);
	while (!(ft_strchr(rest[fd], '\n')) && (ret = read(fd, buff, BUFFER_SIZE)))
	{
		if (ret < 0)
			return (-1);
		temp = rest[fd];
		buff[ret] = '\0';
		if (!(rest[fd] = ft_strjoin(rest[fd], buff)))
			return (-1);
		free(temp);
	}
	free(buff);
	return (ft_store(rest, ret, line, fd));
}
