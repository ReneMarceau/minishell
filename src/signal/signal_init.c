/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:17:09 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/13 16:22:39 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	modify_sig_setup(void)
{
	struct termios	new_attributes;

	tcgetattr(STDIN_FILENO, &new_attributes);
	new_attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &new_attributes);
}

void	sig_init(t_shell *shell)
{
	sigemptyset(&shell->sa.sa_mask);
	shell->sa.sa_flags = SA_SIGINFO;
	modify_sig_setup();
	shell->sa.sa_sigaction = treat_sig;
	sig_state(RESET_SIG);
	ignore_sigquit();
	sigaction(SIGINT, &shell->sa, NULL);
}
