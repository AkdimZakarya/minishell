/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:17:39 by abettach          #+#    #+#             */
/*   Updated: 2021/02/17 12:19:03 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_exit(t_mini *mini)
{
	char	*arg;
	int		j;

	j = -1;
	mini->shell_lvl -= 1;
	if (mini->shell_lvl >= '2')
	{
		arg = "SHLVL=";
		while (mini->envp_g[++j])
			if (ft_strncmp(mini->envp_g[j], arg, ft_strlen(arg)) == 0)
				mini->envp_g = ft_remove_unset(mini, j);
		arg = ft_strjoin(arg, &mini->shell_lvl);
		ft_strjoin2(mini->envp_g, arg);
	}
	else
	{
		while (1)
			exit(0);
	}
}

void		ft_init(t_mini *mini)
{
	mini->run_path = NULL;
	g_input_redirection = 0;
	g_output_redirection = 0;
	mini->STD = 1;
	g_double_input_redirection = 0;
	g_pipe = 0;
	g_input_file = NULL;
	g_output_file = NULL;
	g_double_input_redirection = 0;
	g_double_redirection = NULL;
}
