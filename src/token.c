/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:54:56 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/19 05:32:20 by ykerdel          ###   ########.fr       */
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
	int	loop;

	loop = 1;
	i++;
	while (((*str)[i] && (*str)[i] != token) || loop)
	{
		loop = 0;
		if (token == TK_D_QUOTE && (*str)[i] == TK_DOLLAR)
			i = token_dollar(str, i, g_exit_status);
		i++;
	}
	i++;
	return (i);
}

size_t	token_heredoc(char **str, size_t index)
{
	size_t	start;
	size_t	i;
	size_t	tk_count;
	char	*exit;

	i = index;
	i += 2;
	while ((*str)[i] && (*str)[i] == TK_SPACE)
		i++;
	start = i;
	tk_count = 0;
	while ((*str)[i] && (*str)[i] != TK_SPACE)
	{
		if ((*str)[i] == TK_D_QUOTE || (*str)[i] == TK_S_QUOTE)
			tk_count++;
		i++;
	}
	exit = quote_str_get(ft_substr((*str), start, i - start), tk_count);
	*str = ms_swapstr(*str, NULL, index, i - index);
	printf(GREEN);
	while (ft_strncmp(readline("heredoc>  "), exit, ft_strlen(exit) + 1))
		;
	printf(RESET);
	return (i);
}
