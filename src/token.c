/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:54:56 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/19 05:07:47 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	token_dollar(char **str, int i, int *g_exit_status)
{
	size_t	len;
	size_t	env_len;
	char	*env;

	len = 1;
	if (ft_isalpha((*str)[i + len]) || (*str)[i + len] == TK_UNDERSCORE)
		len++;
	while (ft_isalnum((*str)[i + len]) || (*str)[i + len] == TK_UNDERSCORE)
		len++;
	if ((*str)[i + 1] == TK_QUESTION_MARK)
	{
		env = ft_itoa(*g_exit_status);
		len++;
	}
	else
		env = getenv(ft_substr((*str), i + 1, len - 1));
	if (!env)
		env = NULL;
	(*str) = ms_swapstr((*str), env, i, len);
	env_len = ft_strlen(env);
	return (i + env_len - 1);
}

size_t	token_quote(char **str, size_t i, char token, int *g_exit_status)
{
	return (i);
}

size_t	token_heredoc(char **str, size_t index)
{
	return (index);
}
