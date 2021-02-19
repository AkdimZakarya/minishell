/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:17:33 by abettach          #+#    #+#             */
/*   Updated: 2021/02/17 12:42:38 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_get_path(t_mini *mini)
{
	int			i;
	int			j;
	struct stat buffer;

	i = 0;
	j = 0;
	while (mini->envp_g[i][0] != 'P' || mini->envp_g[i][1] != 'A' ||
	mini->envp_g[i][2] != 'T' || mini->envp_g[i][3] != 'H')
		i++;
	while (mini->envp_g[i][j] != '=')
		j++;
	j++;
	mini->path = &mini->envp_g[i][j];
	mini->add_path = ft_split(mini->path, ':');
	i = 0;
	while (mini->add_path[i])
	{
		mini->add_path[i] = ft_strjoin(mini->add_path[i], "/");
		mini->add_path[i] = ft_strjoin(mini->add_path[i], mini->args[0]);
		i++;
	}
	i = -1;
	while (mini->add_path[++i])
		if (stat(mini->add_path[i], &buffer) == 0)
			mini->run_path = mini->add_path[i];
}

void			ft_get_home(t_mini *mini, char **envp)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (envp[i][0] != 'H' || envp[i][1] != 'O' || envp[i][2] != 'M'
	|| envp[i][3] != 'E')
		i++;
	while (envp[i][j] != '=')
		j++;
	j++;
	mini->home = &envp[i][j];
}
