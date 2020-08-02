/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 17:25:54 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/07/30 17:32:39 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static void		get_flaggs()
{
	i = 0;
	while (i < 32)
	{
		if (*all->format_ptr == flags_str[i])
			
		i++;
	}
}	// poista
*/

static void		get_plain_txt(t_all *all)
{
	intmax_t	len;
	char		*end_ptr;
	t_list		*txt_list;

	ft_putendl("get_plain_txt start");
	if (!(end_ptr = ft_strchr(all->format_ptr, '%')) &&
		!(end_ptr = ft_strchr(all->format_ptr, '\\'))) //might need to seperate
		len = ft_strlen(all->format_ptr);
	else
		len = end_ptr - all->format_ptr;
	txt_list = ft_lstnew(all->format_ptr, len);
	ft_putendl("gpt after lst");
	if (all->parsed_args)
	{
		ft_putendl("parse 1");
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
	ft_putendl("gtp second");
	all->len += len;
	all->format_ptr += len;
}

/* FT_PARSE goes through the format str and collects everything to a
linked list. */

void		ft_parse(t_all *all)
{
	while (all->format_ptr)
	{
		get_plain_txt(all);
		ft_putendl(all->parsed_args->content);
		ft_putendl("ft_parse after get_plain_txt"); //test
		if (all->format_ptr)
		{
			ft_putendl("before get_variable_info");
			get_variable_info(all);
//			get_variable(all);
		}
		ft_putendl("ft_parse end of while");
		while (1); //test
	}
}
