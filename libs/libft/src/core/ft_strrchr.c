/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:12:33 by rmarceau          #+#    #+#             */
/*   Updated: 2023/09/22 09:12:34 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				last;
	unsigned char	c_unsigned;

	c_unsigned = (unsigned char)c;
	if (c_unsigned == '\0')
		return ((char *)&s[ft_strlen(s)]);
	last = ft_strlen(s) - 1;
	if (last < 0)
		return (NULL);
	while (last >= 0)
	{
		if (s[last] == c_unsigned)
			return ((char *)&s[last]);
		last--;
	}
	return (NULL);
}
