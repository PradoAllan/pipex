/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:52:24 by aprado            #+#    #+#             */
/*   Updated: 2024/01/30 16:42:50 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	mandatory_p1(int pfd[], char **args, char **paths)
{
	int		new_fdin;
	char	**cmds;

	cmds = ft_split_cmds(args[2], ' ');
	if (!cmds)
		return (ft_putstr("Comand invalid", 2));
	new_cmds(cmds);
	new_fdin = open(args[1], O_RDONLY);
	if (new_fdin < 0)
		ft_puterror("Error.");
	if (dup2(pfd[WRITE_END], STDOUT_FILENO) == -1)
		ft_puterror("Error.");
	if (dup2(new_fdin, STDIN_FILENO) == -1)
		ft_puterror("Error.");
	close(pfd[READ_END]);
	close(new_fdin);
	close(pfd[WRITE_END]);
	if (execve(paths[0], cmds, NULL) == -1)
		ft_puterror("Error.");
	freematrix_two(paths);
	freematrix_two(cmds);
}

void	mandatory_p2(int pfd[], char **args, char **paths)
{
	int		new_fdout;
	char	**cmds;

	cmds = ft_split_cmds(args[3], ' ');
	if (!cmds)
		return (ft_putstr("Comand invalid.", 2));
	new_cmds(cmds);
	new_fdout = open(args[4], O_CREAT | O_RDWR | O_TRUNC, 00700);
	if (new_fdout < 0)
		ft_puterror("Error.");
	if (dup2(pfd[READ_END], STDIN_FILENO) == -1)
		ft_puterror("Error.");
	if (dup2(new_fdout, STDOUT_FILENO) == -1)
		ft_puterror("Error.");
	close(new_fdout);
	close(pfd[WRITE_END]);
	close(pfd[READ_END]);
	if (execve(paths[1], cmds, NULL) == -1)
		ft_puterror("Error.");
	freematrix_two(paths);
	freematrix_two(cmds);
}

void	mandatory(char **true_paths, char **args)
{
	int	pfd[2];
	int	pid1;
	int	pid2;

	if (pipe(pfd) == -1)
		ft_puterror("Error.");
	pid1 = fork();
	if (pid1 == -1)
		ft_puterror("Error.");
	if (pid1 == 0)
		mandatory_p1(pfd, args, true_paths);
	pid2 = fork();
	if (pid2 == -1)
		ft_puterror("Error.");
	if (pid2 == 0)
		mandatory_p2(pfd, args, true_paths);
	close(pfd[READ_END]);
	close(pfd[WRITE_END]);
	freematrix_two(true_paths);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

void	pipex(char **args, int ac, char **paths, int type)
{
	char	**true_paths;
	int		i;

	true_paths = malloc(sizeof(char *) * ((ac - 3) + 1));
	if (!true_paths)
		return ;
	true_paths[ac - 3] = NULL;
	i = 0;
	while (i < (ac - 3))
	{
		true_paths[i] = true_path_finder(args, (i + 2), paths);
		if (true_paths[i] == NULL)
		{
			freematrix(true_paths, i);
			freematrix_two(paths);
			return ;
		}
		i++;
	}
	freematrix_two(paths);
	if (type == 1)
		mandatory(true_paths, args);
}

int	main(int ac, char **av, char **envp)
{
	char	*env_path;
	char	**paths;

	if (ac != 5 || !av_checker(av, ac))
		return (ft_putstr("Invalid arguments.", 2), 0);
	if (!comand_checker(av[2]) || !comand_checker(av[3]))
		return (ft_putstr("Invalid commands.", 2), 0);
	env_path = env_path_finder(envp);
	if (!env_path)
		return (0);
	paths = ft_split(env_path + 5, ':');
	if (!paths)
		return (0);
	if (ac == 5)
		pipex(av, ac, paths, 1);
	else
		ft_putstr("Invalid arguments.", 2);
	return (1);
}
