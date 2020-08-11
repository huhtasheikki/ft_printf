/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 09:14:21 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/10 15:57:10 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		convert_ptr(void *param)
{
	t_all			*all;

	all = (t_all*)param;
	all->convert_str = ft_uintmaxtoa_base((unsigned long)all->arg_ptr, 16);
	ft_strcpy(all->prefix, "0x");
	all->prefix_len = 2;
	all->arg_len = ft_strlen(all->convert_str);
}

void		get_ptr(t_all *all)
{
	all->arg_ptr = va_arg(all->args, void*);
}
