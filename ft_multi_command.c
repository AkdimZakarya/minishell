/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:17:51 by abettach          #+#    #+#             */
/*   Updated: 2021/02/17 10:53:52 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_remove_space_2(t_mini *mini, int i, int *j, char *str)
{
	while (mini->line[i])
	{
		if ((mini->line[i] == ' ' && mini->line[i + 1] == ';') ||
		(mini->line[i] == ' ' && mini->line[i - 1] == ';'))
			i++;
		str[(*j)] = mini->line[i];
		(*j) = (*j) + 1;
		i++;
	}
}

void		ft_remove_space(t_mini *mini)
{
	int		i;
	int		j;
	int		spaces;
	char	tmp;
	char	*str;

	i = 0;
	j = 0;
	spaces = 0;
	while (mini->line[i])
	{
		if (mini->line[i] == ' ')
			spaces++;
		i++;
	}
	i -= spaces;
	str = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	ft_remove_space_2(mini, i, &j, str);
	str[j] = '\0';
	mini->line = NULL;
	mini->line = str;
}

void		ft_multi_command(t_mini *mini)
{
	ft_remove_space(mini);
	mini->multi_command = ft_split(mini->line, ';');
}

void		ft_check_multi_command_2(t_mini *mini)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	mini->multi_command = malloc(sizeof(char *) * 2);
	mini->multi_command[0] = (char *)malloc(sizeof(char) *
	(ft_strlen(mini->line) + 1));
	while (mini->line[i])
	{
		mini->multi_command[0][j] = mini->line[i];
		i++;
		j++;
	}
	mini->multi_command[0][j] = '\0';
	mini->multi_command[1] = NULL;
}

void		ft_check_multi_command(t_mini *mini)
{
	int		i;
	int		index;

	i = 0;
	index = 0;
	while (mini->line[i])
	{
		if (mini->line[i] == ';')
		{
			index = 5;
			ft_multi_command(mini);
			break ;
		}
		else
			i++;
	}
	if (index == 0)
		ft_check_multi_command_2(mini);
}
