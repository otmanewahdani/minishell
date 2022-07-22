/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_checkers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: owahdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:31:20 by owahdani          #+#    #+#             */
/*   Updated: 2022/07/22 18:15:07 by owahdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*void	mv_2_nxt_quote(char **line)
{
	if (**line == '\'')
	{
		(*line)++;
		while (**line && **line != '\'')
			(*line)++;
		(*line)++;
	}
	else
	{
		(*line)++;
		while (**line && **line != '\"')
			(*line)++;
		(*line)++;
	}
}*/

int	check_quotes(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
		{
			while (line[++i])
				if (line[i] == '\"')
					break ;
		}
		else if (line[i] == '\'')
		{
			while (line[++i])
				if (line[i] == '\'')
					break ;
		}
		if (!line[i])
			return (ft_perror("minishell", QUOTES));
		i++;
	}
	return (0);
}
