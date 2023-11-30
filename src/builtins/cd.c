/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:30:03 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/30 12:50:15 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "env.h"
#include "error.h"

char    *get_env_value(t_env *env, char *key)
{
    t_env *current;

    current = env;
    while (current != NULL)
    {
        if (ft_strcmp(current->key, key) == true)
            return (current->value);
        current = current->next;
    }
    return (NULL);
}

void    set_env_value(t_env *env, char *key, char *value)
{
    t_env *current;

    current = env;
    while (current != NULL)
    {
        if (ft_strcmp(current->key, key) == true)
        {
            free(current->value);
            current->value = ft_strdup(value);
            return ;
        }
        current = current->next;
    }
}

static int     nb_args(char **args)
{
    int i;

    i = 0;
    while (args[i] != NULL)
    {
        if (ft_strlen(args[i]) > 0)
            i++;
    }
    return (i);
}

bool    exec_cd(t_cmd *cmd, t_env *env)
{
    char *pwd;
    char *oldpwd;
    char *home;
    char *path;

    if (cmd->args[1] != NULL && cmd->args[1][0] == '-' && cmd->args[1][1] != '\0')
        return (print_error_builtin(ERR_INVALID_OPT, cmd->args[0], cmd->args[1], 2), false);
    if (nb_args(cmd->args) > 2)
        return (print_error_builtin(ERR_TOO_MANY_ARGS, cmd->args[0], NULL, 1), false);
    pwd = getcwd(NULL, 0);
    oldpwd = get_env_value(env, "OLDPWD");
    home = get_env_value(env, "HOME");
    if (cmd->args[1] == NULL)
    {
        if (home == NULL)
            return (print_error_builtin("HOME not set", cmd->args[0], NULL, 1), false);
        path = ft_strdup(home);
    }
    else if (ft_strcmp(cmd->args[1], "~") == true)
    {
        if (home == NULL)
            return (print_error_builtin("HOME not set", cmd->args[0], NULL, 1), false);
        path = ft_strjoin(home, cmd->args[1] + 1);
    }
    else if (ft_strcmp(cmd->args[1], "-") == true)
    {
        if (oldpwd == NULL)
            return (print_error_builtin("OLDPWD not set", cmd->args[0], NULL, 1), false);
        path = ft_strdup(oldpwd);
        printf("%s\n", oldpwd);
    }
    else
        path = ft_strdup(cmd->args[1]);
    if (chdir(path) == -1)
        return(print_error_builtin(strerror(errno), cmd->args[0], cmd->args[1], 1), false);
    set_env_value(env, "OLDPWD", pwd);
    free(path);
    path = getcwd(NULL, 0);
    set_env_value(env, "PWD", path);
    free(path);
    free(pwd);
    g_exit_status = EXIT_SUCCESS;
    return (true);
}
