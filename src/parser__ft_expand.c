/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__ft_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auzun <auzun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:11:41 by auzun             #+#    #+#             */
/*   Updated: 2022/11/10 15:51:31 by auzun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*cut_there(char *str, int start, int end)
{
	char	*cuted;
	int		i;

	if (!str[start] || !str[end])
		return (NULL);
	cuted = malloc(((end - start) + 1) * sizeof(char));
	if (!cuted)
		return (NULL);
	i = -1;
	while (++i < (end - start))
		cuted[i] = str[start + i];
	cuted[i] = '\0';
	return (cuted);
}

t_lex	*split_str(t_data *data, char *str)
{
	t_lex	*lst;
	t_lex	*new;
	int		start;
	int		end;

	start = 0;
	end = -1;
	lst = NULL;
	printf("%s salut\n", str);
	while (str[++end])
	{
		if ((str[end] == ' ' || !str[end + 1]) && !is_in_quotes(str, &str[end]))
		{
			new = ft_lstnew_lex(cut_there(str, start, end));
			start = end + 1;
			if (!new || !new->str)
			{
				ft_lstclear_lex(&lst);
				free(str);
				free_all_and_exit(data, "malloc");
			}
			ft_lstadd_back_lex(&lst, new);
		}
	}
	return (lst);
}

t_lex	*ft_expand(t_data *data, char *str)
{
	t_lex	*lst;
	char	*expanded;

	if (!is_there_el_outside_quotes(str, '$'))
		return (NULL);
	expanded = check_expand(data, str, 0, 0);
	//free(str);
	lst = split_str(data, expanded);
	if (!lst)
	{
		lst = ft_lstnew_lex(expanded);
		if (!lst)
		{
			free(expanded);
			free_all_and_exit(data, "malloc");
		}
	}
	return (lst);
}