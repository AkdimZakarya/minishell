/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syn_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:35:52 by abettach          #+#    #+#             */
/*   Updated: 2021/02/17 14:25:24 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_syntax_error_2(t_mini *mini, int *i)
{
	if (mini->line[0] == '|')
		return (5);
	if (mini->line[(*i)] == '|' && mini->line[(*i) + 1] == ' ' &&
	mini->line[(*i) + 2] == '|')
		return (6);
	if (mini->line[(*i)] == '<' && !mini->line[(*i) + 1])
		return (7);
	if (mini->line[(*i)] == ';' && mini->line[(*i) + 1] == '|')
		return (8);
	if (mini->line[(*i)] == '|' && mini->line[(*i) + 1] == ';')
		return (9);
	return (0);
}

int		ft_syntax_error(t_mini *mini)
{
	int	i;

	i = 0;
	while (mini->line[i])
	{
		if (mini->line[i] == '>' && mini->line[i + 1] == '>' &&
		mini->line[i + 2] == '>' && mini->line[i + 3] != '>')
			return (1);
		if (mini->line[i] == '>' && mini->line[i + 1] == ' ' &&
		mini->line[i + 2] == '<')
			return (2);
		if (mini->line[i] == '>' && mini->line[i + 1] == '>' &&
		mini->line[i + 2] == '>' && mini->line[i + 3] == '>')
			return (3);
		if (mini->line[i] == ';' && mini->line[i + 1] == ';')
			return (4);
		return (ft_syntax_error_2(mini, &i));
		i++;
	}
	return (0);
}

int		syn_error(t_mini *mini)
{
	int	i;

	i = ft_syntax_error(mini);
	if (i == 1)
		ft_putstr("syntax error near unexpected token `>'");
	else if (i == 2)
		ft_putstr("syntax error near unexpected token `<'");
	else if (i == 3)
		ft_putstr("syntax error near unexpected token `>>'");
	else if (i == 4)
		ft_putstr("syntax error near unexpected token `;;'");
	else if (i == 5 || i == 6)
		ft_putstr("syntax error near unexpected token `|'");
	else if (i == 7)
		ft_putstr("syntax error near unexpected token `newline'");
	else if (i == 8)
		ft_putstr("syntax error near unexpected token `;'");
	else if (i == 9)
		ft_putstr("syntax error near unexpected token `|'");
	else if (i == 0)
		return (0);
	ft_putstr("\n");
	return (1);
}
