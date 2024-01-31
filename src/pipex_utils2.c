/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:15:27 by aprado            #+#    #+#             */
/*   Updated: 2024/01/30 15:40:28 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freematrix(char **matrix, int i )
{
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

int	is_there_quotes(unsigned int index, char const *s)
{
	while (s[index])
	{
		if (s[index] == 39)
			return (index);
		index++;
	}
	return (0);
}
