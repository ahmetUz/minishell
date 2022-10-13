/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:13:01 by auzun             #+#    #+#             */
/*   Updated: 2022/10/13 16:30:04 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/linked_lists.h"

t_fd	*ft_lstnew_fd(int default_fd)
{
	t_fd	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (NULL);
	element->fd = 0;
	element->file = NULL;
	element->operator = NOTHING_R;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}
