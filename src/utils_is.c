/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:39:59 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/10 16:09:44 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

bool	ft_isquote(char a)
{
	return (a == '\'' || a == '\"');
}

bool	ft_isspecial(char a)
{
	return (a == '<' || a == '>' || a == '|');
}

bool	is_sep(char c)
{
	return (ft_isspace(c) || ft_isspecial(c));
}
