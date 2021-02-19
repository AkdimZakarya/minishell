/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:18:18 by abettach          #+#    #+#             */
/*   Updated: 2021/02/16 11:21:43 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_signal(t_mini *mini)
{
	write(1, BLU, COLOR_SIZE);
	ft_putstr("\nminishell$ ");
	write(1, WHT, COLOR_SIZE);
	return (-1);
}

void	ft_ctrl_c(int signum)
{
	waitpid(-1, 0, 0);
	ft_putstr(GRN);
	ft_putstr("\b\b  \n➜  ");
	ft_putstr(RED);
	ft_putstr("minishell");
	ft_putstr(WHT);
	ft_putstr("$ ");
}

void	ft_ctrl_anti(int signum)
{
	waitpid(-1, 0, 0);
	ft_putstr("\b\b  ");
}
