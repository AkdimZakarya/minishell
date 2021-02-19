/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:17:10 by abettach          #+#    #+#             */
/*   Updated: 2021/02/18 12:45:20 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_mini *mini)
{
	int	i;

	i = 0;
	if (mini->ArgsNum <= 1)
	{
		while (mini->envp_g[i])
		{
			ft_putstr(mini->envp_g[i]);
			ft_putstr("\n");
			i++;
		}
	}
}
