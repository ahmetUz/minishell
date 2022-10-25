/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:43:09 by ilandols          #+#    #+#             */
/*   Updated: 2022/10/25 23:20:33 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define TOKENS "<>|&()"

# include "../libft/include/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <dirent.h>

extern int	g_exit_status;

/* temp.c */
void	ft_print_fd(t_fd *fd);
void	print_cmd(t_cmd *commands, char *state);
char	*expand(char *to_find, t_lex *env);

/* lexer_utils.c */
int		is_token(t_lex *element);
t_redi	get_redi(t_lex *element);
t_deli	get_delimiter(t_lex *element);
int		search_closing_quote(t_lex *lexer, char *quote);
int 	search_closing_parenthese(t_lex *lexer);

/* lexer_child.c */
int		define_child(t_data *data);

/* lexer_command.c */
int		define_command(t_data *data);

/* lexer_argument.c */
int	    define_argument(t_data *data);

/* lexer_redi.c */
char	*find_file(t_data *data);
t_fd	*define_fd(t_data *data);
int		define_redi(t_data *data);

/* lexer_delimiter.c */
void	define_delimiter(t_data *data);

/* lexer_initialize.c */
int		concat_ampersand(t_lex **lexer);
int		concat_quotes(t_lex **lexer);
int		concat_tokens(t_lex **lexer);
int		concat_env(t_lex **lexer);
int		concat_lexer(t_data *data);

/* lexer.c */
void	get_lexer(t_data *data);
void	lexer(t_data *data);

/*============================================================================*/

/*dir utils*/
t_lex	*send_dir_content(char *path, int only_dir, int *err);
char	*concate_paths(char *path, char *finded);

/*wildcard*/
t_lex	*wildiwonkard(t_data *data, char *path);
t_lex	*find_occurrences(t_lex *paths, int *err);

/* parser.c */
void	parser(t_data *data);


/* minishell.c */
void	minishell(t_data *data);

/* utils.c */
int		is_there(char *str, char in);
char	*expand(char *to_find, t_lex *env);

/* free_memory.c */
void	free_lexer_struct(t_lex **lexer);
void	free_fd_struct(t_fd **list);
void	free_command_struct(t_cmd **commands);
void	free_data_struct(t_data *data);
void	free_all_and_exit(t_data *data, char *str_error);

/* initialize.c */
void	initialize_data(t_data *data, char **envp);

/* main.c */
int		main(int ac, char **av, char **envp);

#endif
