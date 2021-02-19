/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:18:14 by abettach          #+#    #+#             */
/*   Updated: 2021/02/17 15:12:58 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_input_redirection(t_mini *mini, int i)
{
    int j = -1;
    int index;

    mini->redirection = 1;
    index = i;
    i++;
    g_input_redirection = 1;
    mini->STD = 1;
    g_input_file = (char *)malloc(sizeof(char) * (ft_strlen(mini->args[i]) + 1));
    while (mini->args[i][++j])
        g_input_file[j] = mini->args[i][j];
    g_input_file[++j] = '\0';
    while (mini->args[index])
    {
        mini->args[index] = NULL;
        mini->ArgsNum--;
        index++;
    }
    int fd = open(g_input_file, O_RDWR | O_CREAT | O_TRUNC, 0777);
    dup2(fd, mini->STD);
}

void ft_output_redirection(t_mini *mini, int i)
{
    int j = -1;
    int index;

    mini->redirection = 1;
    g_output_redirection = 1;
    index = i;
    i++;
    mini->STD = 0;
    g_output_file = (char *)malloc(sizeof(char) * (ft_strlen(mini->args[i]) + 1));
    while (mini->args[i][++j])
        g_output_file[j] = mini->args[i][j];
    g_output_file[++j] = '\0';
    while (mini->args[index])
    {
        mini->args[index] = NULL;
        mini->ArgsNum--;
        index++;
    }
    int fd = open(g_output_file, O_RDWR, 0777);
    dup2(fd, mini->STD);
}

void ft_double_input_redirection(t_mini *mini, int i)
{
    int j = -1;
    int index;

    mini->redirection = 1;
    g_double_input_redirection = 1;
    index = i;
    i++;
    mini->STD = 1;
    g_double_redirection = (char *)malloc(sizeof(char) * (ft_strlen(mini->args[i]) + 1));
    while (mini->args[i][++j])
        g_double_redirection[j] = mini->args[i][j];
    g_double_redirection[++j] = '\0';
    while (mini->args[index])
    {
        mini->args[index] = NULL;
        mini->ArgsNum--;
        index++;
    }
    int fd = open(g_double_redirection, O_RDWR | O_CREAT | O_APPEND, 0777);
    dup2(fd, mini->STD);
}

int ft_check_redirection(t_mini *mini)
{
    int i = 0;
    int j = 0;

    mini->redirection = 0;
    while (mini->args[i])
    {
        mini->STD = -1;
        if (ft_strcmp(mini->args[i], ">") == 0 && mini->args[i + 1])
            ft_input_redirection(mini, i);
        else if (ft_strcmp(mini->args[i], "<") == 0 && mini->args[i + 1])
            ft_output_redirection(mini, i);
        else if (ft_strcmp(mini->args[i], ">>") == 0 && mini->args[i + 1])
            ft_double_input_redirection(mini, i);
        i++;
    }

    return 0;
}