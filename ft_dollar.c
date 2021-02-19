/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettach <abettach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:16:48 by abettach          #+#    #+#             */
/*   Updated: 2021/02/13 17:10:44 by abettach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_get_value(t_mini *mini, char *arg)
{
    int i = 0, j = 0, k = -1, dollar = 0, s = 0;
    char *rest;

    rest = "";
    mini->dollar.value = "";

    if (mini->dollar_num > 1)
        mini->echo.args = ft_split(arg, '$');
    else if (mini->dollar_num == 1)
    {
        mini->echo.args = malloc(sizeof(char *) * 2);
        mini->echo.args[0] = (char *)malloc(sizeof(char) * (ft_strlen(arg) + 1));
        mini->echo.args[0] = ft_strcpy(mini->echo.args[0], arg);
        mini->echo.args[1] = NULL;
    }
    if (mini->echo.args[i][0] == '%')
    {
        mini->dollar.value = "$";
        mini->dollar.value = ft_strjoin(mini->dollar.value, mini->echo.args[i]);
    }
    while (mini->echo.args[i])
    {
        s = 0;
        while (mini->echo.args[i][s])
        {
            if (mini->echo.args[i][s] == '%' || mini->echo.args[i][s] == '+' || mini->echo.args[i][s] == '-' || mini->echo.args[i][s] == '=' || mini->echo.args[i][s] == 92)
            {
                rest = (char *)malloc(sizeof(char) * (ft_strlen(&mini->echo.args[i][s]) + 1));
                if (mini->echo.args[i][s] == 92)
                    rest = ft_strjoin("$", &mini->echo.args[i][s + 1]);
                else
                    rest = ft_strjoin("$", &mini->echo.args[i][s]);
                break;
            }
            s++;
        }
        mini->echo.args[i] = ft_strjoin(mini->echo.args[i], "=");
        k = -1;
        j = 0;
        while (mini->envp_g[++k])
            if (ft_strncmp(mini->envp_g[k], mini->echo.args[i], ft_strlen(mini->echo.args[i])) == 0)
            {
                while (mini->envp_g[k][j] != '=')
                    j++;
                j++;
                if (mini->echo.args[i + 1])
                    mini->dollar.value = ft_strjoin(mini->dollar.value, rest);
                mini->dollar.value = ft_strjoin(mini->dollar.value, &mini->envp_g[k][j]);
            }
        if (mini->echo.args[i][0] == '?')
        {
            ft_putchar(mini->exit_status + 48);
            ft_putstr(&mini->echo.args[i][1]);
        }
        i++;
    }
    mini->dollar.value = ft_strjoin(mini->dollar.value, rest);
}

void ft_get_num_dollar(t_mini *mini, char *arg)
{
    int i = 0;
    while (arg[i])
    {
        if (arg[i] == '$')
            mini->dollar_num++;
        i++;
    }
}

void ft_dollar(t_mini *mini)
{
    int i = 1;
    int j = 1;
    int dollar = 0;

    ft_skipe_quotes(mini);
    while (mini->args[i])
    {
        mini->dollar_num = 0;
        ft_get_num_dollar(mini, mini->args[i]);
        if (mini->args[i][0] == '$' && mini->args[i][1])
        {
            if ((mini->args[i][j] >= '0' && mini->args[i][j] <= '9'))
            {
                while ((mini->args[i][j] >= '0' && mini->args[i][j] <= '9'))
                    j++;
                mini->args[i] = &mini->args[i][j];
            }
            else
            {
                ft_get_value(mini, &mini->args[i][1]);
                mini->args[i] = mini->dollar.value;
            }
        }
        i++;
    }
}