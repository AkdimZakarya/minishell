/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:18:08 by abettach          #+#    #+#             */
/*   Updated: 2021/02/16 11:23:20 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_mini *mini)
{
	getcwd(mini->cwd, ft_strlen(mini->cwd));
	ft_putstr(mini->cwd);
	ft_putstr("\n");
}
