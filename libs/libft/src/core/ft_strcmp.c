/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rene <rene@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 23:03:44 by rene              #+#    #+#             */
/*   Updated: 2023/11/29 23:07:53 by rene             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

bool    ft_strcmp(const char *s1, const char *s2)
{
    bool result;

    if (ft_strncmp(s1, s2, ft_strlen(s1)) == 0 && ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
        result = true;
    else
        result = false;
    return (result);
}
