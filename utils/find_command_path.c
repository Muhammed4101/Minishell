/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atam <atam@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:58:29 by muharsla          #+#    #+#             */
/*   Updated: 2025/09/16 10:42:40 by atam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>
#include "gc.h"
#include "libft/libft.h"

static char	*join_path_dir(const char *dir, const char *cmd)
{
	int		ld;
	int		lc;
	char	*full;

	ld = ft_strlen(dir);
	lc = ft_strlen(cmd);
	full = gc_malloc(ld + lc + 2);
	if (!full)
		return (NULL);
	ft_strcpy(full, dir);
	full[ld] = '/';
	ft_strcpy(full + ld + 1, cmd);
	return (full);
}

static char	*find_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (gc_strdup(envp[i] + 5));
		i++;
	}
	return (NULL);
}

static char	*try_in_paths(const char *cmd, char *paths)
{
	char	**dirs;
	int		i;
	char	*full;

	dirs = gc_split(paths, ':');
	i = 0;
	while (dirs && dirs[i])
	{
		full = join_path_dir(dirs[i], cmd);
		if (access(full, X_OK) == 0)
		{
			return (full);
		}
		i++;
	}
	return (NULL);
}

char	*find_command_path(const char *cmd, char **envp)
{
	char	*paths;
	char	*res;

	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (gc_strdup(cmd));
		return (NULL);
	}
	paths = find_path_env(envp);
	if (!paths)
		return (NULL);
	res = try_in_paths(cmd, paths);
	return (res);
}
