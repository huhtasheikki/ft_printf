/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:44:38 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/09 11:57:02 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void		lst_delete(void *data, size_t i)
{
	ft_bzero(data, i);
	free(data);
}

static void		ft_write_lst(t_list *lst, size_t *len)
{
	t_list		*ptr;

	ptr = lst;
	*len = 0;
	while (lst)
	{
		write(1, lst->content, lst->content_size);
		*len += lst->content_size;
		lst = lst->next;
	}
	ft_lstdel(&ptr, &lst_delete);
}

int				ft_printf(const char *format, ...)
{
	t_all		all;
	size_t		len;

	if (!(ft_initialize(&all, format, &len)))
		return (-1); // nolla vai miinus yksi
	if (*all.format_ptr) //onko oikein
	{
		va_start(all.args, format);
		ft_parse(&all);
		va_end(all.args);
	}
	ft_write_lst(all.parsed_args, &len);
	return (len);
}
