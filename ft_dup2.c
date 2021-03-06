/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:16:55 by abettach          #+#    #+#             */
/*   Updated: 2021/02/18 14:33:46 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dup2(t_mini *mini)
{
	int	fdd;

	if (mini->STD == 1)
		fdd = dup(0);
	else
		fdd = dup(1);
	dup2(fdd, mini->STD);
}
