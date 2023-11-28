/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:11:07 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/28 14:23:01 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

size_t expand_return(t_token *current, size_t start, t_shell *shell)
{
	char *exit_code;
	
	printf("%d\n", WEXITSTATUS(g_exit_status));
	exit_code = ft_itoa(WEXITSTATUS(g_exit_status));
	if(make_new_ext_tk(current, start, 2, exit_code) == ERROR)
		shell->mem_err_flg = TRUE;
	return (ft_strlen(exit_code));
}
