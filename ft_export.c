/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:17:20 by abettach          #+#    #+#             */
/*   Updated: 2021/02/17 17:46:04 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_sort_table(t_mini *mini)
{
	int		i;
	char	*tmp;

	i = 0;
	while (mini->export.tab[i + 1] != NULL)
	{
		if (ft_strcmp(mini->export.tab[i], mini->export.tab[i + 1]) > 0)
		{
			tmp = mini->export.tab[i];
			mini->export.tab[i] = mini->export.tab[i + 1];
			mini->export.tab[i + 1] = tmp;
			i = 0;
		}
		else if (ft_strcmp(mini->export.tab[i], mini->export.tab[i + 1]) <= 0)
			i++;
	}
	i = 0;
	while (mini->export.tab[i])
	{
		ft_putstr("declare -x ");
		ft_putstr(mini->export.tab[i]);
		ft_putstr("\n");
		i++;
	}
}

void		ft_skipe_quotes(t_mini *mini)
{
	int		i;
	int		j;
	int		k;
	char	**new_tab;

	i = 0;
	if (ft_check_quotes(mini) == 1)
	{
		new_tab = malloc(sizeof(char *) * (mini->ArgsNum + 1));
		while (mini->args[i])
		{
			new_tab[i] = (char *)malloc(sizeof(char) *
			(ft_strlen(mini->args[i]) + 1));
			k = 0;
			j = 0;
			while (mini->args[i][j])
			{
				if (mini->args[i][j] == '"')
					j++;
				new_tab[i][k++] = mini->args[i][j++];
			}
			i++;
		}
		mini->args = new_tab;
	}
}

void		ft_export_2(t_mini *mini, int i, char *arg)
{
	int		j;

	while (i < mini->ArgsNum)
	{
		j = 0;
		while (mini->args[i][j] != '=')
			j++;
		arg = (char *)malloc(sizeof(char) * (j + 2));
		ft_strlcpy(arg, mini->args[i], j);
		j = -1;
		while (mini->envp_g[++j])
			if (ft_strncmp(mini->envp_g[j], arg, ft_strlen(arg)) == 0)
				mini->envp_g = ft_remove_unset(mini, j);
		ft_strjoin2(mini->envp_g, mini->args[i]);
		i++;
	}
}

void		ft_export(t_mini *mini)
{
	int		i;
	char	*arg;

	i = 1;
	ft_skipe_quotes(mini);
	if (mini->ArgsNum > 1)
	{
		if ((mini->args[i][0] >= 'a' && mini->args[i][0] <= 'z') ||
			(mini->args[i][0] >= 'A' && mini->args[i][0] <= 'Z') ||
			(mini->args[i][0] == '_'))
		{
			if (ft_equal_check(mini, mini->args[i]) == 1)
				ft_export_2(mini, i, arg);
		}
		else
		{
			ft_error("bash: export: ", mini->args[i],
			": not a valid identifier\n");
		}
	}
	if (mini->ArgsNum == 1)
	{
		mini->export.tab = ft_copy_export(mini, mini->envp_g);
		ft_sort_table(mini);
	}
}
