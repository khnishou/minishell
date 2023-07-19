/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:02:20 by ykerdel           #+#    #+#             */
/*   Updated: 2023/07/19 05:23:27 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft.h"
# include "./get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"

typedef enum e_error_code
{
	VALID,
	MALLOC_ERR,
}	t_error;

enum e_token
{
	TK_DOLLAR			= '$',
	TK_S_QUOTE			= '\'',
	TK_D_QUOTE			= '"',
	TK_LESS				= '<',
	TK_GREATER			= '>',
	TK_PIPE				= '|',
	TK_QUESTION_MARK	= '?',
	TK_SPACE			= ' ',
	TK_NEW_LINE			= '\n',
	TK_UNDERSCORE		= '_',
	TK_HYPHEN			= '-',
	TK_PERIOD			= '.',
	TK_TAB				= '\t'
}	t_token;

typedef struct s_exe
{
	size_t			index;
	size_t			nbr_pipe;
}	t_exe;

//	init.c
t_exe		*ms_init(char *input, int *g_exit_status);

//	utils.c
size_t		ms_count_char(char *input, char c);
char		*ms_swapstr(char *src, char *swap, size_t start, size_t len);
char		*quote_str_get(char *str, size_t tk_count);

//	exit.c
void		ms_exit(t_error err);

//	token.c
size_t		token_dollar(char **str, int index, int *g_exit_status);
size_t		token_quote(char **str, size_t i, char token, int *g_exit_status);
size_t		token_heredoc(char **str, size_t index);

#endif
