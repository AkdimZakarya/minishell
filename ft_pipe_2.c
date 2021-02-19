/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:23:37 by zakdim            #+#    #+#             */
/*   Updated: 2021/02/16 15:55:12 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pipe(t_mini *mini, int i)
{
	ft_remove_pipe_space(mini, i);
	mini->pipe.args = ft_split(mini->multi_command[i], '|');
}

void	ft_init_pipe(t_mini *mini)
{
	int i;

	i = 0;
	if (mini->pipe.args[i])
	{
		mini->pipe.args[i] = NULL;
		free(mini->pipe.args[i]);
		i++;
	}
}

void	ft_get_pipe_args(t_mini *mini, int k)
{
	int	i;
	int	arg;
	int	carg;

	i = -1;
	arg = -1;
	carg = 0;
	mini->args = ft_split(mini->pipe.args[k], ' ');
	while (mini->args[++i])
		;
	mini->ArgsNum = i;
}

int		ft_check_pipe(t_mini *mini, char **envp, int i)
{
	int	j;

	j = 0;
	while (mini->multi_command[i][j])
	{
		if (mini->multi_command[i][j] == '|')
			return (1);
		j++;
	}
	return (0);
}
