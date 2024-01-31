/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:17:41 by aprado            #+#    #+#             */
/*   Updated: 2024/01/29 18:12:31 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	wordslen(char const *s, char c, unsigned int i)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static unsigned int	count_words(char const *s, char c, unsigned int i)
{
	unsigned int	words;

	words = 1;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
		i++;
	if (is_there_quotes(i, s))
		change_space((char *)s, i);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	freeall(char **matrix, unsigned int i)
{
	i--;
	while ((int)i >= 0)
	{
		free(matrix[i]);
		i--;
	}
}

static char	**core(char const *s, char c, char **matrix, unsigned int words)
{
	unsigned int	index;
	unsigned int	x;
	size_t			wordslength;

	index = -1;
	x = 0;
	while (x < words && s[++index] != '\0')
	{
		if (s[index] != c)
		{
			wordslength = wordslen(s, c, index);
			matrix[x] = ft_substr_cmds(s, index, wordslength);
			if (matrix[x] == NULL)
			{
				freeall(matrix, x);
				free(matrix);
				return (NULL);
			}
			index = index + wordslength;
			x++;
		}
	}
	return (matrix);
}

char	**ft_split_cmds(char const *s, char c)
{
	char			**matrix;
	unsigned int	words;
	unsigned int	index;

	if (!(s))
		return (NULL);
	index = 0;
	words = count_words(s, c, index);
	if (words == 0)
		return (NULL);
	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);
	matrix[words] = 0;
	matrix = core(s, c, matrix, words);
	change_tab(matrix, words);
	return (matrix);
}
