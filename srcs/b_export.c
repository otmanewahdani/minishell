/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahdan <achahdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 21:26:49 by achahdan          #+#    #+#             */
/*   Updated: 2022/08/09 19:36:34 by achahdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <string.h>

int	search_for_var(t_env *env, const char *var)
{
	int	i;

	i = 0;
	while (env)
	{
		if (strncmp(env->var, var, strlen(var)) == 0)
			return (i);
		env = env->next;
		i++;
	}
	return (-1);
}

char	**split_arg(char *arg)
{
	int	i;
	char	**tab;

	i = 0;
	tab = malloc(sizeof(char *) * 4);
	while (arg[i] && arg[i] != '=')
		i++;
	if (arg[i - 1] == '+')
	{
		tab[0] = ft_substr(arg, 0, i - 1);
		tab[2] = ft_strdup("+");
	}
	else
	{
		tab[0] = ft_substr(arg, 0, i);
		tab[2] = ft_strdup("-");
	}
	arg++;
	tab[1] = ft_substr(arg + i, 0, ft_strlen(arg) - i);
	tab[3] = 0;
	return (tab);
}

int	check_naming(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		ft_perror("minishell", "export: `': not a valid identifier",0);
		return (-1);
	}
	while (str[i])
	{
		if(!ft_isalnum(str[i]) && str[i] != '_')
		{
			ft_perror("minishell", "export: `': not a valid identifier",0);
			return (-1);
		}
		i++;
	}
	return (1);
}

void	add_node(t_env **lst, char *var, char *value)
{
	t_env	*ptr;
	t_env *new;

	if (!lst)
		return ;
	new = malloc(sizeof(t_env));
	new->var = var;
	new->value = value;
	new->next = NULL;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	replace_value(t_env *env, int index)
{
	int	i;

	i = -1;
	while (i++ < index && env->next)
		env = env->next;
	printf("%s,\n",env->var);
}

void	export(t_env *env, char **args)
{
	int i;
	char **sp_arg;

	// if (!args)
	// 	//print in alpha order + return
	i = 0;
	while (args[i])
	{
		sp_arg = split_arg(args[i]);
		if (check_naming(sp_arg[0]) == 1)
		{
			if (sp_arg[2][0] == '-' && search_for_var(env, sp_arg[0]) == -1)
				add_node(&env,sp_arg[0], sp_arg[1]);
			else if (sp_arg[2][0] == '-' && search_for_var(env, sp_arg[0]) != -1)
			{
				printf("sig?\n");
				replace_value(env, search_for_var(env, sp_arg[0]));
			}
				// add
		}
		free(sp_arg);
		i++;
	}
}
