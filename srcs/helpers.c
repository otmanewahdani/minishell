/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owahdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:23:19 by owahdani          #+#    #+#             */
/*   Updated: 2022/07/24 17:52:42 by owahdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_strndup(const char *s1, size_t size)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (size > len)
		size = len;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	check_malloc(void *to_be_checked, void *to_be_freed)
{
	if (to_be_checked)
		return (0);
	free(to_be_freed);
	ft_perror("minishell", NULL, 0);
	g_data.exit_code = 1;
	return (-1);
}

void	mv_2_nxt_quote(char *line, int *i)
{
	if (line[*i] == '\'')
	{
		(*i)++;
		while (line[*i] && line[*i] != '\'')
			(*i)++;
		(*i)++;
	}
	else
	{
		(*i)++;
		while (line[*i] && line[*i] != '\"')
			(*i)++;
		(*i)++;
	}
}
