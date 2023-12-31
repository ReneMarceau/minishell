/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:11:07 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/14 23:43:00 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t	expand_return(t_token *current, size_t start, t_shell *shell)
{
	char	*exit_code;

	exit_code = ft_itoa(g_exit_status);
	if (make_new_ext_tk(current, start, 2, exit_code) == ERROR)
		shell->mem_err_flg = TRUE;
	return (ft_strlen(exit_code));
}

size_t	expand_return_here(t_expand *test, size_t start, t_shell *shell)
{
	char	*exit_code;

	exit_code = ft_itoa(g_exit_status);
	if (make_new_ext_here(test, start, 2, exit_code) == ERROR)
		shell->mem_err_flg = TRUE;
	return (ft_strlen(exit_code));
}
