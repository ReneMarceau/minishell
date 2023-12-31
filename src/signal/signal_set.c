/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:20:05 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/14 17:51:32 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	set_to_heredoc(t_shell *shell)
{
	shell->sa.sa_sigaction = treat_here;
	sigaction(SIGINT, &shell->sa, NULL);
	ignore_sigquit();
}

void	set_to_process(t_shell *shell)
{
	shell->sa.sa_sigaction = treat_in_process;
	sigaction(SIGINT, &shell->sa, NULL);
	sigaction(SIGQUIT, &shell->sa, NULL);
}

void	set_to_inter(t_shell *shell)
{
	sig_state(RESET_SIG);
	shell->sa.sa_sigaction = treat_sig;
	sigaction(SIGINT, &shell->sa, NULL);
	sigaction(SIGQUIT, &shell->sa, NULL);
}

void	ignore_sigall(void)
{
	ignore_sigint();
	ignore_sigquit();
}
