/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:26:27 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/15 11:21:10 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdbool.h>

/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
t_env				*create_node_env(char *key, char *value);
void				insert_env(t_env **head, t_env *new_node);
void				unset_env(t_env **head, char *key);
bool				split_key_value(char *env, char **key, char **value);
t_env				*find_env(t_env *env, char *key);
int					count_node_env(t_env *head);
t_env				*build_env_list(char **env);
char				**env_to_array(t_env *head);
#endif