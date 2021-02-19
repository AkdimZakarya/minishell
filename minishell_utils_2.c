/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:50:25 by zakdim            #+#    #+#             */
/*   Updated: 2021/02/17 12:02:08 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void				ft_putstr(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int					char_test(char *command, char *str)
{
	int				i;

	i = 0;
	if (command[i] == '\0' || command[i] == '\n')
	{
		return (0);
	}
	while (command[i])
	{
		if ((command[i] - str[i]) == 0)
			i++;
		else
			return (0);
	}
	return (1);
}

int					ft_ischar(char c)
{
	if ((c >= 'a' && c <= 'z') || ((c >= 'A') && (c <= 'Z')) || (c == '-') ||
	(c == '|') || (c == '"') || (c == '.') || (c == '/') || (c == '~') ||
	(c == '&') || (c == '>') || (c >= '0' && c <= '9') || c == ';' ||
	c == '=' || (c == '*') || (c == '$') || (c == 39) || (c == '<') ||
	(c == 92) || (c == '\t') || (c == '#') || (c == '%') || (c == '{') ||
	(c == '}') || (c == ':') || (c == '!') || (c == '@') || (c == '`') ||
	(c == '.') || (c == ',') || (c == '^') || (c == '*') || (c == '(') ||
	(c == ')') || (c == '+') || (c == '?') || (c == '_'))
		return (1);
	return (0);
}

int					ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	if (s1 == NULL)
		return (1);
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while ((s11[i] || s22[i]))
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

char				**ft_strjoin2(char **s1, char *s2)
{
	char			*ret;
	int				i;
	int				j;
	int				count;

	j = 0;
	count = 0;
	i = (ft_strlen(s2) + 1);
	while (s1[i])
		i++;
	s1[i] = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	while (s2[j])
	{
		s1[i][j] = s2[j];
		j++;
	}
	s1[i][j] = '\0';
	i++;
	s1[i] = NULL;
	return (s1);
}
