/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:13:04 by aprado            #+#    #+#             */
/*   Updated: 2024/01/30 15:49:41 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# define WRITE_END 1
# define READ_END 0

// <--- Functions Mandatory --->
int		ft_strlen(char *s);
int		ft_space_strlen(char *s);
int		av_checker(char **av, int ac);
int		ft_strncmp(char *s1, char *s2, int n);
int		comand_checker(char *s);
int		is_there_quotes(unsigned int index, char const *s);
char	*env_path_finder(char **env);
char	**ft_split(char const *s, char c);
char	**ft_split_cmds(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr_cmds(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*true_path_finder(char **args, int ac, char **paths);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putstr(char *s, int fd);
void	freematrix(char **matrix, int i);
void	freematrix_two(char **matrix);
void	ft_puterror(char *s);
void	change_tab(char **matrix, unsigned int words);
void	change_space(char *s, unsigned int index);
void	new_cmds(char **cmds);

#endif
