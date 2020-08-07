/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:48:20 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/06 18:37:00 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_reset_format_info(t_all *all)
{
	bzero(all->prefix, PREFIX + 1);
	all->width = 0;
	all->precision = 0; // 0 or 1;
	all->flags = 0;
	all->format_info = 0;
//	all->format_id = '\0';
	all->format_id = 0;
	all->padding_len = 0;
	all->padding_char = ' ';
	all->padding_str = ft_strnew(0);
	all->arg_len = 0;
	all->combined_len = 0;
}
