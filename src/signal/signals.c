/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:54 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/15 01:03:07 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

// void signaltreat(int signal, siginfo_t *info, void *context)
// {
// 	(void)info;
// 	(void)context;
// 	(void)signal;
// 	sigignore(signal);
// 	rl_replace_line();
// 	printf("\n");
// }

// void signalhandler(void)
// {
// 	struct sigaction sa;

// 	sa.sa_sigaction = signaltreat;
// 	sigemptyset(&sa.sa_mask);
// 	sa.sa_flags = SA_SIGINFO;
// 	sigaction(SIGINT, &sa, NULL);
// }
