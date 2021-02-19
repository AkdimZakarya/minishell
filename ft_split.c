/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:18:22 by abettach          #+#    #+#             */
/*   Updated: 2021/02/16 10:16:31 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t			len;
	size_t			first;
	size_t			last;
	size_t			x;
	char			*tab;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	first = ft_first(s1, set, 0);
	if (first == len)
		return (ft_strdup(""));
	haha : last = ft_last(s1, set, len);
	if (last < first)
		return (0);
	tab = malloc(last - first + 1);
	x = 0;
	if (!tab)
		return (0);
	while (s1[first] != '\0' && first < last)
		tab[x++] = s1[first++];
	tab[x] = '\0';
	return (tab);
}

static	int			c_word(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
			i = skip_quots(str, str[i], i);
		if (str[i] == c && str[i + 1] != c)
			count++;
		if (str[i] != c && str[i + 1] == '\0')
			count++;
	}
	return (count);
}

static	void		ft_free(char **tab, char *str)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(str);
}

static	char		*remplir(char *s, int *k, char c)
{
	int				i;
	int				start;
	int				end;
	char			*str;
	int				startt;

	i = *k;
	while (s[i] == c)
		i++;
	start = i;
	startt = i;
	while (s[i] != c && s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			i = skip_quots(s, s[i], i);
		i++;
	}
	end = i;
	*k = i;
	while (startt < end)
		startt++;
	str = ft_substr(s, start, (end - start));
	if (str == NULL)
		return (NULL);
	return (str);
}

char				**ft_split(char const *s, char c)
{
	char			*str;
	char			**tab;
	int				i;
	int				j;
	int				k;

	if (s == NULL)
		return (NULL);
	i = -1;
	str = ft_strtrim(s, &c);
	if (str == NULL)
		return (NULL);
	j = c_word(str, c);
	tab = (char **)malloc((j + 1) * sizeof(char*));
	if (tab == NULL)
		return (NULL);
	k = 0;
	while (++i < j)
		if ((tab[i] = remplir(str, &k, c)) == NULL)
		{
			ft_free(tab, str);
			return (0);
		}
	tab[i] = 0;
	return (tab);
}
