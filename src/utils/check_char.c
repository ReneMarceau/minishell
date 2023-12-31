/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:39:59 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/15 10:59:50 by rmarceau         ###   ########.fr       */
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

bool	is_there_quote(char *token)
{
	size_t	i;

	i = 0;
	while (token[i])
		if (ft_isquote(token[i++]))
			return (TRUE);
	return (FALSE);
}
