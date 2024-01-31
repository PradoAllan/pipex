/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_comand_checker.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:07:13 by aprado            #+#    #+#             */
/*   Updated: 2024/01/29 18:16:08 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	is_quote(char *s)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == 39)
			quote++;
		i++;
	}
	if (quote % 2 == 0)
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
	if (is_quote(s))
		return (1);
	return (0);
}
