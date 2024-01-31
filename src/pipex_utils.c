/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 08:50:40 by aprado            #+#    #+#             */
/*   Updated: 2024/01/23 14:08:01 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(1, "\n", 1);
}

static int	is_there_args(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ((s[i] > 8 && s[i] < 14) || (s[i] == ' ')))
		i++;
	if (s[i] == '\0')
		return (0);
	return (1);
}

int	av_checker(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i] == NULL)
			return (0);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if (!is_there_args(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	while (*s1 == *s2 && n > 0 && *s1)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
