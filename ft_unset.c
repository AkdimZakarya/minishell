/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:18:57 by abettach          #+#    #+#             */
/*   Updated: 2021/02/15 18:01:02 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_remove_unset2(t_mini *mini, int index, char **tab)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (mini->envp_g[++i])
	{
		if (i != index)
		{
			tab[j] = (char *)malloc(sizeof(char) *
				(ft_strlen(mini->envp_g[i] + 1)));
			tab[j] = ft_strcpy(tab[j], mini->envp_g[i]);
			j++;
		}
	}
}

char		**ft_remove_unset(t_mini *mini, int index)
{
	char	**tab;
	int		line;
	int		i;
	int		j;

	line = 0;
	i = -1;
	j = 0;
	while (mini->envp_g[line])
		line++;
	tab = malloc(sizeof(char *) * (line + 1));
	ft_remove_unset2(mini, index, tab);
	i = -1;
	while (mini->envp_g[++i])
		mini->envp_g[i] = NULL;
	i = -1;
	while (tab[++i])
	{
		mini->envp_g[i] = (char *)malloc(sizeof(char) *
				(ft_strlen(tab[i] + 1)));
		mini->envp_g[i] = ft_strcpy(mini->envp_g[i], tab[i]);
	}
	return (tab);
}

void		ft_unset(t_mini *mini)
{
	char	*arg;
	int		i;
	int		j;

	j = 1;
	if (mini->ArgsNum > 1)
		while (j < mini->ArgsNum)
		{
			if ((ft_equal_check(mini, mini->args[j])) == 0)
			{
				arg = ft_strjoin(mini->args[j], "=");
				i = -1;
				while (mini->envp_g[++i])
					if (ft_strncmp(mini->envp_g[i], arg, ft_strlen(arg)) == 0)
						mini->envp_g = ft_remove_unset(mini, i);
				j++;
			}
			else
			{
				ft_putstr("unset: ");
				ft_putstr(mini->args[j]);
				ft_putstr(": invalid parameter name\n");
				break ;
			}
		}
}
