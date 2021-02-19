/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 10:07:22 by zakdim            #+#    #+#             */
/*   Updated: 2021/02/16 15:28:05 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_first(char const *s1, char const *set, size_t j)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0' && s1[j] != '\0')
	{
		if (s1[j] == set[i])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

size_t	ft_last(char const *s1, char const *set, size_t j)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[j - 1] == set[i])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}
