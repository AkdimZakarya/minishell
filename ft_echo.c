/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:17:04 by abettach          #+#    #+#             */
/*   Updated: 2021/02/19 14:39:14 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo_2(t_mini *mini, int *i, int *deja)
{
	if ((ft_strcmp(mini->args[(*i)], "-n") == 0) && (*deja) == 0)
	{
		while ((ft_strcmp(mini->args[(*i)], "-n") == 0))
			(*i) = (*i) + 1;
		(*deja) = 1;
	}
}

void	ft_echo(t_mini *mini)
{
	int	i;
	int	j;
	int	deja;
	int	len;

	i = 1;
	j = 0;
	deja = 0;
	ft_skipe_quotes(mini);
	while (mini->args[i])
	{
		ft_echo_2(mini, &i, &deja);
		if (mini->args[i][j] == 92)
			j++;
		len = ft_strlen(mini->args[i]) - 1;
		if (mini->args[i][len] == 92)
			mini->args[i][len] = '\0';
		ft_putstr(&mini->args[i][j]);
		if (i + 1 < mini->ArgsNum)
			ft_putstr(" ");
		i++;
	}
	if (ft_strcmp(mini->args[1], "-n") != 0)
		ft_putstr("\n");
}
