/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:33:33 by rmarceau          #+#    #+#             */
/*   Updated: 2023/11/16 15:03:21 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
# include <stdbool.h>

/* *************** ***************           *************** *************** */
/*                                  Macros                                   */
/* *************** ***************           *************** *************** */

/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */

/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
bool    is_builtin(char *cmd_name);
bool    exec_builtin(char *cmd_name);

#endif