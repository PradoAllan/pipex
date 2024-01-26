/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:42 by aprado            #+#    #+#             */
/*   Updated: 2024/01/10 14:06:14 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*
int	main(void)
{
	char	*path = "pipex";
	char	*arguments[] = {"Allan", "prado", "da", "silva", "42", "RIO", NULL};
	execve(path, arguments, NULL);
	printf("ERROR!");
	return (0);
}
*/

int	main(int ac, char **av)
{
	(void)ac;
	execve("pipex", av, NULL);
	printf("ERROR 2");
	return (0);
}
