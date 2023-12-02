/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:54 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/01 19:21:51 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "signals.h"
#include "colors.h"

// int *sig_val(void)
// {
// 	static int sig_val = 0;

// 	return (&sig_val);
// }

void treat_sig(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	(void)signal;
	// sigignore(signal);
	// rl_replace_line();
	
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0); //test
	rl_redisplay(); //test
	// readline(READLINE_MSG);
}

void sig_handle(t_shell *shell)
{
	struct sigaction sa;
	
	(void)shell;
	sa.sa_sigaction = treat_sig;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
	// sigaction(SIGQUIT, &sa, NULL);
}
