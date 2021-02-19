/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:17:28 by abettach          #+#    #+#             */
/*   Updated: 2021/02/17 16:12:19 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_check_args(t_mini *mini)
{
	int	i;

	i = 0;
	while (i < mini->ArgsNum && mini->args[i])
	{
		if ((mini->args[i][0] == '~' && mini->args[i][1] == '/') ||
		(mini->args[i][0] == '~' && mini->args[i][1] == '\0'))
			mini->args[i] = ft_strjoin(mini->home, &mini->args[i][1]);
		i++;
	}
}

int		ft_get_args(t_mini *mini)
{
	int	i;
	int	arg;
	int	carg;

	i = 0;
	arg = -1;
	carg = 0;
	mini->args = ft_split(mini->line, ' ');
	while (mini->args[i])
		i++;
	mini->ArgsNum = i;
	return (0);
}
