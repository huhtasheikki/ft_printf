/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:25:54 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/11 11:24:34 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_plain_txt(t_all *all)
{
	intmax_t	len;
	char		*end_ptr;
	t_list		*txt_list;

	if (!(end_ptr = ft_strchr(all->format_ptr, '%')) &&
		!(end_ptr = ft_strchr(all->format_ptr, '\\'))) //might need to seperate
		len = ft_strlen(all->format_ptr);
	else
		len = end_ptr - all->format_ptr;
	if(!(txt_list = ft_lstnew(all->format_ptr, len)))
		return (0);
	ft_lstappend(&all->last_arg, txt_list);
	all->last_arg = all->last_arg->next;
	all->len += len;
	all->format_ptr += len;
	return (1);
}

/* FT_PARSE goes through the format str and collects everything to a
linked list. */

int				ft_parse(t_all *all)
{
	while (all->format_ptr && *all->format_ptr)
	{
		if (!get_plain_txt(all))
			return (0);
		if (!get_variable(all))
			return (0);
	}
	return (1);
}
