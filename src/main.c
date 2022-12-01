/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:42:47 by ilandols          #+#    #+#             */
/*   Updated: 2022/12/01 14:44:43 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	g_exit_status;

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)ac;
	(void)av;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, replace_sig_int);
	g_exit_status = 0;
	initialize_data(&data, envp);
	minishell(&data);
	if (data.start_env)
		free_lexer_struct(&data.start_env);
	free_data_struct(&data);
	return (0);
}
