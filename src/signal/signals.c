/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:50:54 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/05 20:00:44 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void treat_here(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	all_free();
	if (signal == SIGQUIT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0); //test
		rl_redisplay(); //test
	}
	if (signal == SIGQUIT)
	{
		printf("QUIT: 3\n");
		rl_on_new_line();
		rl_replace_line("", 0); //test
		rl_redisplay(); //test
	}
}

void	treat_in_process(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGINT)
	{
		kill(0, 0);
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0); //test
		rl_redisplay(); //test
	}
	else if (signal == SIGQUIT)
	{
		kill(0, 0);
		printf("QUIT: 3\n");
		rl_on_new_line();
		rl_replace_line("", 0); //test
		rl_redisplay(); //test
	}
}

void treat_sig(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	// sigignore(signal);
	// rl_replace_line();
	if (signal == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0); //test
		rl_redisplay(); //test
	}
	// readline(READLINE_MSG);
}









// // void sig_handle(t_shell *shell, int type)
// // {
// // 	struct sigaction sa;
	
// // 	(void)shell;
// // 	if (type == SIGINT_INTER)
// // 	{
// // 		sa.sa_sigaction = treat_sig;
// // 		sigemptyset(&sa.sa_mask);
// // 		sa.sa_flags = SA_SIGINFO;
// // 		sigaction(SIGINT, &sa, NULL);
// // 	}
// // 	if (type == SIGINT_HERE)
// // 	{
		


// 	}
// 	// sigaction(SIGQUIT, &sa, NULL);
// }
