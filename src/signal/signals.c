/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:54 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/28 12:17:36 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "colors.h"

// void signaltreat(int signal, siginfo_t *info, void *context)
// {
// 	(void)info;
// 	(void)context;
// 	(void)signal;
// 	sigignore(signal);
// 	rl_replace_line(READLINE_MSG, ft_strlen(READLINE_MSG));
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
