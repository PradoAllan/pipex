/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_comand_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:07:13 by aprado            #+#    #+#             */
/*   Updated: 2024/01/24 15:21:26 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_quote(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			break ;
		i++;
	}
	while (len != 0)
	{
		if (s[len] == 34 || s[len] == 39)
			break ;
		len--;
	}
	if (s[i] == s[len] && len != i)
		return (1);
	return (0);
}

int	comand_checker(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (0);
	while (s[i] > 8 && s[i] < 14)
		i++;
	if (len == i)
		return (0);
	while (s[i])
		i++;
	if (i == len)
		return (1);
	if (is_quote(s))
		return (1);
	return (0);
}
