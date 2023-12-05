/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:49:55 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/04 21:19:53 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H


/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
# include "global.h"
// # include <termios.h>
// # include <signal.h>
/* *************** ***************           *************** *************** */
/*                                  Macros                                   */
/* *************** ***************           *************** *************** */
# define IN_INTERFACE 1
# define IN_HEREDOC 2
# define IN_PROCESS 3


/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */



/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
//signal_parse -----------------
int *if_sig_int(int context, t_shell *shell);
void sig_handle(t_shell *shell, int type);
//signal -----------------------
void treat_sig(int signal, siginfo_t *info, void *context);
void treat_here(int signal, siginfo_t *info, void *context);
void treat_in_process(int signal, siginfo_t *info, void *context);
//signal_set -------------------
void modify_sig_setup(void);
void sig_init(t_shell *shell, int type);
void set_to_heredoc(t_shell *shell);
void set_to_process(t_shell *shell);
#endif