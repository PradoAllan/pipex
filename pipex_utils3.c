/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:33:03 by aprado            #+#    #+#             */
/*   Updated: 2024/01/29 17:15:38 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	change_tab(char **matrix, unsigned int words)
{
	unsigned int	x;
	unsigned int	j;

	x = 0;
	while (x < words && matrix[x])
	{
		j = 0;
		while (matrix[x][j])
		{
			if (matrix[x][j] == '\t')
				matrix[x][j] = ' ';
			j++;
		}
		x++;
	}
}

void	change_space(char *s, unsigned int index)
{
	while (s[index] != 39)
		index++;
	if (s[index] == 39)
	{
		while (s[index])
		{
			if (s[index] == ' ')
				s[index] = '\t';
			index++;
		}
	}
}

static int	in(char const *str, char ch)
{
	while (*str && ch != *str)
		str++;
	if (ch == *str)
		return (1);
	else
		return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	if (!(s1))
		return (NULL);
	first = 0;
	last = ft_strlen((char *)s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (in(set, s1[first]))
		first++;
	if (first == last)
		return (ft_strdup(""));
	while (in(set, s1[last - 1]))
		last--;
	return (ft_substr_cmds(s1, first, last - first));
}

/*
char	*ft_substr_cmds(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	int		j;

	if (!(s))
		return (NULL);
	i = 0;
	j = (int)start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	new = (char *)malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (len > 0)
	{
		new[i] = s[j];
		i++;
		j++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
*/
