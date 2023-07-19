/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:54:56 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/19 04:39:18 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	token_dollar(char **str, int i, int *g_exit_status)
{
	return (i);
}

size_t	token_quote(char **str, size_t i, char token, int *g_exit_status)
{
	return (i);
}

size_t	token_heredoc(char **str, size_t index)
{
	return (index);
}
