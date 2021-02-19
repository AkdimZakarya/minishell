/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:18:49 by abettach          #+#    #+#             */
/*   Updated: 2021/02/16 09:57:43 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_sorte_args_2(t_mini *mini, int *i, int j)
{
	while (mini->args[j])
	{
		mini->sort_args[(*i)] = (char *)malloc(sizeof(char) *
		(ft_strlen(mini->args[j] + 1)));
		mini->sort_args[(*i)] = ft_strcpy(mini->sort_args[(*i)], mini->args[j]);
		j++;
		(*i) = (*i) + 1;
	}
}

void		ft_sorte_args(t_mini *mini)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	mini->sort_args = malloc(sizeof(char *) * (mini->ArgsNum + 1));
	if ((ft_strcmp(mini->args[0], ">") == 0 || ft_strcmp(mini->args[0],
	">>") == 0 || ft_strcmp(mini->args[0], "<") == 0) && mini->args[2])
	{
		ft_sorte_args_2(mini, &i, j);
		j = 0;
		while (mini->args[j] && j < 2)
		{
			mini->sort_args[i] = (char *)malloc(sizeof(char) *
			(ft_strlen(mini->args[j] + 1)));
			mini->sort_args[i] = ft_strcpy(mini->sort_args[i], mini->args[j]);
			j++;
			i++;
		}
		mini->sort_args[i] = NULL;
		mini->args = mini->sort_args;
	}
}

void		ft_start_minishell_2(t_mini *mini)
{
	ft_get_args(mini);
	ft_sorte_args(mini);
	ft_get_path(mini);
	ft_check_args(mini);
	ft_dollar(mini);
	ft_check_redirection(mini);
}

void		ft_start_minishell(t_mini *mini)
{
	int		i;
	int		fdd;
	int		fd[2];
	pid_t	pid;

	i = 0;
	pipe(fd);
	while (mini->multi_command[i] != NULL)
	{
		mini->check_pipe = 0;
		ft_check_pipe_command(mini, i);
		mini->line = ft_strcpy(mini->line, mini->multi_command[i]);
		ft_init(mini);
		if (mini->check_pipe == 0)
			ft_start_minishell_2(mini);
		ft_run_command(mini);
		ft_dup2(mini);
		ft_init_pipe(mini);
		i++;
	}
}
