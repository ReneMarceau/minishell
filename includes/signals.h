/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:49:55 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/04 17:07:36 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H


/* *************** ***************           *************** *************** */
/*                                  INCLUDES                                 */
/* *************** ***************           *************** *************** */
# include "global.h"
// # include <signal.h>
/* *************** ***************           *************** *************** */
/*                                  Macros                                   */
/* *************** ***************           *************** *************** */
# define NO_SIG 0
# define SIGINT_INTER 1
# define SIGINT_HERE 2
# define SIGINT_PROC 3
# define SIGQUIT_INTER 4
# define SIGQUIT_HERE 5
# define SIGQUIT_PROC 6


/* *************** ***************           *************** *************** */
/*                                  Structures                               */
/* *************** ***************           *************** *************** */



/* *************** ***************           *************** *************** */
/*                                  Prototypes                               */
/* *************** ***************           *************** *************** */
//signal_parse -----------------
int *if_sigint(int condition);
void sig_handle(t_shell *shell, int type);
//signal -----------------------
void treat_sig(int signal, siginfo_t *info, void *context);
void treat_here(int signal, siginfo_t *info, void *context);

#endif