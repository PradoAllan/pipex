/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:17:41 by aprado            #+#    #+#             */
/*   Updated: 2024/01/16 09:44:28 by aprado           ###   ########.fr       */
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

	words = 0;
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
			matrix[x] = ft_substr(s, index, wordslength);
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

char	**ft_split(char const *s, char c)
{
	char			**matrix;
	unsigned int	words;
	unsigned int	index;

	if (!(s))
		return (NULL);
	index = 0;
	words = count_words(s, c, index);
	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);
	matrix[words] = 0;
	return (core(s, c, matrix, words));
}
