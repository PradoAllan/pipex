/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freematrix_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:29:51 by aprado            #+#    #+#             */
/*   Updated: 2024/01/30 15:48:23 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freematrix_two(char **matrix)
{
	int	i;

	i = 0;
	if (matrix[i])
	{
		while (matrix[i])
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}
