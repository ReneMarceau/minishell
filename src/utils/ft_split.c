/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:11:42 by rmarceau          #+#    #+#             */
/*   Updated: 2023/12/11 12:37:05 by rmarceau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"
#include "garbage_collector.h"

static void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		free(array[i++]);
}

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_fill_array(char **aux, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;
	size_t	s_len;

	i = 0;
	k = 0;
	s_len = ft_strlen(s);
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (j >= s_len)
			aux[k++] = "\0";
		else
		{
			aux[k++] = ft_substr(s, j, i - j);
			add_garbage(aux[k - 1]);
		}
	}
	return (aux);
}

char	**ft_split(char const *s, char c)
{
	char	**aux;
	int		nwords;

	if (!s)
		return (NULL);
	nwords = ft_count_words(s, c);
	aux = list_malloc((nwords + 1), sizeof(char *));
	if (aux == NULL)
		return (ft_free_array(aux), NULL);
	aux = ft_fill_array(aux, s, c);
	aux[nwords] = NULL;
	return (aux);
}
