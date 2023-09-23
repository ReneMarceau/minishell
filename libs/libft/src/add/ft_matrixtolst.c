/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixtolst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:06:22 by rmarceau          #+#    #+#             */
/*   Updated: 2023/09/22 09:06:23 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_matrixtolst(char **matrix)
{
	t_list	*lst;
	int		i;

	lst = NULL;
	i = -1;
	while (matrix[++i])
		ft_lstadd_back(&lst, ft_lstnew(ft_strdup(matrix[i])));
	return (lst);
}
