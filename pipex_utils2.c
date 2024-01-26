/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:15:27 by aprado            #+#    #+#             */
/*   Updated: 2024/01/25 14:25:30 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freematrix(char **matrix, int i )
{
	int	x;

	x = 0;
	if (i == 0)
	{
		while (matrix[x])
		{
			free(matrix[x]);
			x++;
		}
		free(matrix);
		return ;
	}
	i--;
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
}

void	ft_puterror(char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

int	ft_space_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] == ' ')
		len++;
	if (s[len] != ' ')
	{
		while (s[len] && s[len] != ' ')
			len++;
	}
	return (len);
}

char	*ft_substr_cmds(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;
	int		j;

	if (!(s))
		return (NULL);
	i = 0;
	j = (int)start;
	if ((int)start >= ft_strlen((char *)s))
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

/*
int	is_there_two_quotes(char *s)
{
	int	i;
	int	len;

	len = ft_strlen((char *)s);
	while (s[i])
	{
		if (s[i] == 34)
		{
			while (len != 0)
				if (s[len--] == 34 && len > i)
					return (1);
		}
		i++;
	}
	i = 0;
	len = ft_strlen((char *)s);
	while (s[i])
	{
		if (s[i] == 39)
		{
			while (len != 0)
				if (s[len--] == 39 && len > 1)
					return (1);
		}
		i++;
	}
	return (0);
}*/
