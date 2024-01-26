/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:17:41 by aprado            #+#    #+#             */
/*   Updated: 2024/01/25 21:35:40 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	wordslen(char const *s, char c, unsigned int i)
{
	size_t	len;

	//"awk '{print $1}'\0"
	len = 0;
	if (s[i] && (s[i] == 39 || s[i] == 34))
	{
		i++;
		len++;
		while (s[i] != 39 && s[i] != 34)
		{
			i++;
			len++;
		}
	}
	else
	{
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
	}
	return (len);
}

static unsigned int	count_words(char const *s, char c, unsigned int i)
{
	unsigned int	words;
	unsigned int	quote;
	/*
	unsigned int	j;
	unsigned int	k;

	words = 1;
	j = i;
	k = ft_strlen((char *)s);
	if (i == k)
		words++;
	while (s[j] && s[j] != 34)
		j++;
	while (k != 0 && s[k] != 34)
		k--;
	if (s[j] != s[k])
		return (0);
	*/

	words = 0;
	quote = 0;
	while (s[i])
	{
		if (s[i] == 39 || s[i] == 34)
		{
			quote++;
			if (quote == 0)
				words++;
		}
		if (quote == 0 && (s[i] != 39 && s[i] != 34))
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
	//"awk '{print $1}'\0"
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
//	while (s[index] && s[index] == ' ')
//		index++;
//	while (s[index] && s[index] != ' ')
//		index++;
	words = count_words(s, c, index);
	if (words == 0)
		return (NULL);
	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);
	matrix[words] = 0;
	return (core(s, c, matrix, words));
}
