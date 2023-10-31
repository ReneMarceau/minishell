/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:54 by wmillett          #+#    #+#             */
/*   Updated: 2023/10/30 22:54:06 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"



void signaltreat(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	// sigignore(signal);
	// rl_replace_line();
	printf("\n");
}



void signalhandler(void)
{
	struct sigaction sa;

	sa.sa_sigaction = signaltreat;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
}
