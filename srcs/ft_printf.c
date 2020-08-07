/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:44:38 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/07 11:37:25 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

void	ft_write_lst(t_list *lst)
{
	while (lst)
	{
		write(1, lst->content, lst->content_size);
		lst = lst->next;
	}
}

int		ft_printf(const char *format, ...)
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
	ft_write_lst(all.parsed_args);
//	ft_putstr(all.ready_print);
//	len = ft_strlen(all.ready_print);
//	ft_del_all(&all);
	return (len);
//	return (ft_strlen(all.ready_print));
}
