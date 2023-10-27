/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:10:48 by rene              #+#    #+#             */
/*   Updated: 2023/10/26 21:37:38 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "error.h"
#include "colors.h"

void	print_error(char *error_message, char *arg) {
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(TAG, STDERR_FILENO);
	if (arg) {
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(error_message, STDERR_FILENO);
	ft_putendl_fd(RESET, STDERR_FILENO);
}
