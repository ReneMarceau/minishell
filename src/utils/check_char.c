/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:39:59 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/14 17:33:20 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

bool	ft_isquote(char c)
{
	return (c == '\'' || c == '\"');
}

bool	ft_isspecial(char c)
{
	return (c == '<' || c == '>' || c == '|');
}

bool	is_sep(char c)
{
	return (ft_isspace(c) || ft_isspecial(c));
}

bool	ft_isexpand(char c)
{
	return (ft_isalnum(c) || c == '_');
}
