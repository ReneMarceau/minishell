/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:03:30 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/14 18:10:10 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "parse.h"

static size_t count_space(char *input)
{
	size_t symbol;
	size_t i;

	symbol = 0;
	i = 0;
	while(input[i])
	{
		if (ft_isquote(input[i]))
			i += through_quote(input, i, NULL, FALSE);
		else if (ft_isspecial(input[i]))
		{
			i += through_special(input, i);
			symbol++;
		}
		else if (ft_isspace(input[i]))
			input[i++] = SEP;
		else
			i++;
	}
	return (ft_strlen(input) + (symbol * 2));
}

static size_t make_space(char *dst, char *src, size_t pos_dst, size_t pos_src)
{
	const size_t len = through_special(src, pos_src);
	size_t i;

	i = 0;
	dst[pos_dst++] = SEP;
	while(i < len)
	{
		dst[pos_dst++] = src[pos_src];
		i++;
	}
	dst[pos_dst] = SEP;
	return (len + 2);
}

static size_t	str_sep_cpy(char *dst, char *src)
{
	const size_t len = ft_strlen(src);
	size_t	i;
	size_t 	j;
	
	i = 0;
	j = 0;
	while (i < len)
	{
		if (ft_isquote(src[i]))
		{
			j += through_quote(src, i, dst, j);
			i += through_quote(src, i, NULL, FALSE);
		}
		else if (ft_isspecial(src[i]))
		{
			j += make_space(dst, src, j, i);
			i += through_special(src, i);
		}
		else
			dst[j++] = src[i++];
	}
	dst[j] = '\0';
	return (j);
}

char	*str_sel_dup(char *s1)
{
	char	*d;
	size_t	size;

	if (!s1)
		return (NULL);
	size = count_space(s1);
	d = (char *)malloc(size + 1);
	if (!d)
		return (NULL);
	str_sep_cpy(d, s1);
	return (d);
}
