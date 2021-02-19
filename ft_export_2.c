/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:09:56 by zakdim            #+#    #+#             */
/*   Updated: 2021/02/18 12:42:13 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_copy_env(t_mini *mini, char **envp)
{
	int		line;
	int		i;
	char	**tab;

	line = 0;
	i = -1;
	while (envp[line])
		line++;
	tab = malloc(sizeof(char *) * (line + 1));
	while (envp[++i])
	{
		tab[i] = (char *)malloc(sizeof(char) * (ft_strlen(envp[i] + 1)));
		tab[i] = ft_strcpy(tab[i], envp[i]);
	}
	return (tab);
}

char		**ft_copy_export(t_mini *mini, char **envp)
{
	char	**tab;
	int		i;
	int		k;
	int		j;

	i = -1;
	j = 0;
	while (mini->envp_g[j])
		j++;
	tab = malloc(sizeof(char *) * (j + 1));
	while (mini->envp_g[++i])
	{
		tab[i] = (char *)malloc(sizeof(char) * (ft_strlen(envp[i] + 3)));
		j = -1;
		k = 0;
		while (mini->envp_g[i][++j])
		{
			if (mini->envp_g[i][j - 1] == '=')
				tab[i][k++] = '"';
			tab[i][k++] = mini->envp_g[i][j];
		}
		tab[i][k] = '"';
		tab[i][++k] = '\0';
	}
	return (tab);
}

int			ft_check_quotes(t_mini *mini)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (mini->args[i])
	{
		j = 0;
		while (mini->args[i][j])
		{
			if (mini->args[i][j] == '"')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
