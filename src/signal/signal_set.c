/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:20:05 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/05 19:23:03 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void modify_sig_setup(void) 
{
    struct termios new_attributes;

    tcgetattr(STDIN_FILENO, &new_attributes);
    new_attributes.c_lflag &= ~ECHOCTL;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_attributes);
}

void sig_init(t_shell *shell, int type)
{
	sigemptyset(&shell->sa.sa_mask);
	shell->sa.sa_flags = SA_SIGINFO;
	modify_sig_setup();
	shell->sa.sa_sigaction = treat_sig;
	sigaction(SIGINT, &shell->sa, NULL);
	// sigaction(SIGQUIT, &sa, NULL);
}

void set_to_heredoc(t_shell *shell)
{
	shell->sa.sa_sigaction = treat_here;
	sigaction(SIGINT, &shell->sa, NULL);
	sigaction(SIGQUIT, &shell->sa, NULL);
}

void set_to_process(t_shell *shell)
{
	shell->sa.sa_sigaction = treat_in_process;
	sigaction(SIGINT, &shell->sa, NULL);
	sigaction(SIGQUIT, &shell->sa, NULL);
}
