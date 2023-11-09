/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmillett <wmillett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:39:59 by wmillett          #+#    #+#             */
/*   Updated: 2023/11/08 20:03:08 by wmillett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

bool ft_isquote(char a)
{
	return (a == '\'' || a == '\"');
}

bool ft_isspecial(char a)
{
	return (a == '<' || a == '>' || a == '|');
}

bool	is_sep(char c)
{
	return (ft_isspace(c) || ft_isspecial(c));
}


// void ft_strlselcpy(char *dst, const char *src, int start, int end)
// {
// 	unsigned int	i;
// 	size_t			size_src;

// 	i = 0;
// 	if (src == NULL)
// 		return (0);
// 	size_src = end - start;
// 	if ((int)size < 0)
// 		size = size_src + 1;
// 	if (size >= 2 && size_src != 0)
// 	{
// 		while (i < size - 1)
// 		{
// 			if (i < size_src)
// 				dst[i] = src[i];
// 			else if (i == size_src)
// 				dst[i] = '\0';
// 			i++;
// 		}
// 	}
// 	if (size != 0)
// 		dst[i] = '\0';
// 	return (size_src);
// }

// char	*ft_strldup(const char *s1, int start, int end)
// {
// 	char	*dest;
// 	size_t	size;

// 	if (!s1)
// 		return (NULL);
// 	size = end - start;
// 	dest = (char *)malloc(size + 1);
// 	if (!dest)
// 		return (NULL);
// 	ft_strlselcpy(dest, s1, start, end);
// 	return (dest);
// }
