/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owahdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:57:24 by owahdani          #+#    #+#             */
/*   Updated: 2022/08/14 00:56:37 by owahdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	check_if_allocate(t_env **tmp)
{
	static int	i;

	if (i)
	{
		(*tmp)->next = ft_malloc(1, sizeof(t_env), 1);
		*tmp = (*tmp)->next;
	}
	i = 1;
}

void	init_env_lst(char **env)
{
	static size_t	i[2];
	t_env			*tmp;
	char			**strs;

	while (env[i[0]])
		i[0]++;
	i[1] = i[0];
	i[0] = 0;
	g_data.env_lst = ft_malloc(1, sizeof(t_env), 1);
	tmp = g_data.env_lst;
	while (i[0] < i[1])
	{
		strs = ft_split(env[i[0]++], '=');
		if (!ft_strcmp(strs[0], "OLDPWD"))
		{
			free(strs);
			continue ;
		}
		check_if_allocate(&tmp);
		tmp->var = strs[0];
		tmp->value = strs[1];
		free(strs);
	}
	tmp->next = NULL;
}
