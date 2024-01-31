/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprado <aprado@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:13:41 by aprado            #+#    #+#             */
/*   Updated: 2024/01/30 15:41:16 by aprado           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*env_path_finder(char **env)
{
	char	*env_path;
	int		i;

	i = 0;
	env_path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			env_path = env[i];
			break ;
		}
		i++;
	}
	return (env_path);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	new = (char *)malloc((len + 2) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (len > 0)
	{
		new[i] = s[j];
		i++;
		j++;
		len--;
	}
	new[i] = '/';
	new[i + 1] = '\0';
	return (new);
}

char	*ft_strdup(const char *s)
{
	size_t	strlen;
	size_t	i;
	char	*dup;

	i = 0;
	strlen = ft_strlen((char *)s);
	dup = (char *)malloc((strlen + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < strlen)
		dup[i++] = *s++;
	dup[strlen] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	int		i;
	int		j;
	char	*new;

	if (!(s1))
		return (NULL);
	i = 0;
	s1len = ft_strlen((char *)s1);
	s2len = ft_space_strlen((char *)s2);
	new = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (i < s1len)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2len)
		new[i++] = s2[j++];
	new[s1len + s2len] = '\0';
	return (new);
}

char	*true_path_finder(char **args, int ac, char **paths)
{
	char	*true_path;
	char	*test_path;
	int		access_result;
	int		i;

	i = 0;
	while (paths[i])
	{
		test_path = ft_strjoin(paths[i], args[ac]);
		access_result = access(test_path, F_OK & X_OK);
		if (access_result == 0)
		{
			true_path = test_path;
			return (true_path);
		}
		else
			free(test_path);
		i++;
	}
	ft_puterror("Error path finder:");
	return (NULL);
}
