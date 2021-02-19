/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:38:37 by abettach          #+#    #+#             */
/*   Updated: 2021/02/17 12:18:09 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t				ft_strlen(const char *s)
{
	size_t			i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	int				i;

	if (!s1 || !s2)
		return (0);
	i = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(ret = malloc(i)))
		return (0);
	while (*s1)
		*ret++ = *s1++;
	while (*s2)
		*ret++ = *s2++;
	*ret = '\0';
	return (ret - i + 1);
}

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			length;
	char			*tab;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	length = ft_strlen(&s[start]);
	if (length >= len)
		length = len;
	tab = (char *)malloc((length + 1));
	if (!tab)
		return (0);
	while (i < length && s[start] != '\0')
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}

char				*ft_strdup(const char *s1)
{
	char			*str;
	int				i;
	int				j;

	j = 0;
	if (!s1)
		return (0);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char				*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}
