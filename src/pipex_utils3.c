/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:33:03 by aprado            #+#    #+#             */
/*   Updated: 2024/01/29 18:31:20 by aprado           ###   ########.fr       */
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

void	new_cmds(char **cmds)
{
	int		x;
	int		j;
	int		quotes;
	char	*temp;

	x = 0;
	while (cmds[x])
	{
		j = 0;
		quotes = 0;
		while (cmds[x][j])
		{
			if (cmds[x][j] == 39)
				quotes++;
			j++;
		}
		if (quotes >= 2)
		{
			temp = cmds[x];
			cmds[x] = ft_strtrim(cmds[x], "'");
			free(temp);
		}
		x++;
	}
}
