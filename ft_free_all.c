#include "minishell.h"

void ft_free_all(t_mini *mini)
{
    int i = 0;
    while (mini->cwd[i])
    {
        mini->cwd[i] = '\0';
        i++;
    }
    i = 0;
    //////multi command == > prob
    // if (mini->multi_command)
    //     free(mini->multi_command);
    // while (mini->multi_command[i])
    // {
    //     free(mini->multi_command[i]);
    //     i++;
    // }
    /////pipe command
    i = 0;
    if (mini->pipe.args)
        free(mini->pipe.args);
    while (mini->pipe.args[i])
    {
        free(mini->pipe.args[i]);
        i++;
    }
    //line
    if (mini->line)
        free(mini->line);
    ////args ==> prob
    // i = 0;
    // if (mini->args)
    //     free(mini->args);
    // while (mini->args[i])
    // {
    //     free(mini->args[i]);
    //     i++;
    // }
    //srted_args
    i = 0;


}