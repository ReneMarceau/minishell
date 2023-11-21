/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:26:27 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/10 14:18:50 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */
typedef struct s_env {
    char    *key;
    char    *value;
    struct s_env    *next;
}   t_env;

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
t_env   *create_node_env(char *key, char *value);
void    insert_env(t_env **head, t_env *new_node);
int     count_node_env(t_env *head);
t_env   *build_env_list(char **env);
char    **env_to_array(t_env *head);
#endif