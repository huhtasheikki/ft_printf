/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:25:54 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/08 11:26:44 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_plain_txt(t_all *all)
{
	intmax_t	len;
	char		*end_ptr;
	t_list		*txt_list;

	if (!(end_ptr = ft_strchr(all->format_ptr, '%')) &&
		!(end_ptr = ft_strchr(all->format_ptr, '\\'))) //might need to seperate
		len = ft_strlen(all->format_ptr);
	else
		len = end_ptr - all->format_ptr;
	txt_list = ft_lstnew(all->format_ptr, len);
	if (all->parsed_args)
	{
		ft_lstappend(&all->parsed_args, txt_list);
		//use somehow all->last_arg ?
	}
// turha if-else?
/*
	else
	{
		ft_putendl("parse 2");
		all->parsed_args = txt_list;
		ft_putendl("parse 2 loppu");
	}
*/
	all->len += len;
	all->format_ptr += len;
}

/* FT_PARSE goes through the format str and collects everything to a
linked list. */

void		ft_parse(t_all *all)
{
	while (all->format_ptr && *all->format_ptr)
	{
		get_plain_txt(all);
		if (all->format_ptr && *all->format_ptr)
		{
			get_variable_info(all);
			get_variable(all);
		}
	}
}
