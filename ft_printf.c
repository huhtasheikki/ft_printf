/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:44:38 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/29 11:56:29 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_all		all;
//	size_t		len;

	if (!(ft_initialize(&all, format)))
		return (0); // nolla vai miinus yksi
	if (*all.format_ptr) //onko oikein
	{
		va_start(all.ap, format);
		ft_parser(&all);
		va_end(all.ap);
	}
	ft_putstr(all.ready_print);
//	len = ft_strlen(all.ready_print);
	ft_del_all(&all);
//	return (len);
	return (ft_strlen(all.ready_print));
}
