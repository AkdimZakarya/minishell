/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:47:30 by zakdim            #+#    #+#             */
/*   Updated: 2021/02/17 11:55:40 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while ((s11[i] || s22[i]) && i < n)
	{
		if (s11[i] != '\0' && s22[i] == '\0')
			return (s11[i]);
		if (s11[i] == '\0' && s22[i] != '\0')
			return (-s22[i]);
		if (s11[i] > s22[i])
			return (s11[i] - s22[i]);
		if (s11[i] < s22[i])
			return (s11[i] - s22[i]);
		i++;
	}
	return (0);
}

char				*ft_strcpy(char *dst, const char *src)
{
	size_t			i;

	i = 0;
	src = (char *)src;
	if (!(src))
		return (0);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int					ft_equal_check(t_mini *mini, char *arg)
{
	int				i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char				*ft_strlcpy(char *dst, const char *src, int size)
{
	int				i;

	i = 0;
	src = (char *)src;
	while (src[i] != '\0' && size != 0 && (i < (size + 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void				ft_error(char *error_msg, char *command, char *line)
{
	ft_putstr(error_msg);
	ft_putstr(command);
	ft_putstr(line);
}
