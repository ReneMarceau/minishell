/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:39:59 by wmillett          #+#    #+#             */
/*   Updated: 2023/12/04 16:26:12 by wmillett         ###   ########.fr       */
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

bool is_there_quote(char *str)
{
	size_t i;
	
	i = 0;
	while (str[i])
	{
		if (ft_isquote(str[i++]))
			return (TRUE);
	}
	return (FALSE);
}
