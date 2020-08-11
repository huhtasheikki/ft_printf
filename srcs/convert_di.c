/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:10:53 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/10 16:54:47 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			combine_elements(t_all *all)
{
	if (!(all->full_str = ft_strnew(all->combined_len + 1)))
		return ; // make as zero and change return value to int;
	if ((all->format_info & (1 << MINUS_INDEX)))
	{
		ft_strcat(all->full_str, all->prefix);
		ft_strncat(all->full_str, all->convert_str, all->arg_len);
		ft_strcat(all->full_str, all->padding_str);
	}
	else if ((all->format_info & (1 << ZERO_INDEX)))
	{
		ft_strcat(all->full_str, all->prefix);
		ft_strcat(all->full_str, all->padding_str);
		ft_strncat(all->full_str, all->convert_str, all->arg_len);
	}
	else
	{
		ft_strcat(all->full_str, all->padding_str);
		ft_strcat(all->full_str, all->prefix);
		ft_strncat(all->full_str, all->convert_str, all->arg_len);
	}
}

void			convert_ouxx(void *param)
{
	t_all		*all;

	all = (t_all*)param;
//	if (all->arg_uint == 0 && all->precision == 0)
//		all->convert_str = ft_strnew(0);
//	else
		all->convert_str = ft_uintmaxtoa_base(all->arg_uint, all->arg_base);
	if ((all->format_id & (1 << UPX_INDEX)))
		ft_strtoupper(all->convert_str);
	all->arg_len = ft_strlen(all->convert_str);
}

void			convert_di(void *param)
{
	t_all		*all;

	all = (t_all*)param;
	if ((all->format_info & (1 << L_INDEX)) || \
		(all->format_info & (1 << LL_INDEX)))
		all->convert_str = ft_ltoa_base_prefix(all->arg_int, all->arg_base, all->prefix);
	else
		all->convert_str = ft_itoa_base_prefix(all->arg_int, all->arg_base, all->prefix);
	all->prefix_len = ft_strlen(all->prefix);
	all->arg_len = ft_strlen(all->convert_str);
}

void			convert_double(void *param)
{
	t_all		*all;

	all = (t_all*) param;
	if (!(all->format_info & (1 << PRECISION_INDEX)))
		all->convert_str = ft_ftoa(all->arg_double, 6);
	else
		all->convert_str = ft_ftoa(all->arg_double, all->precision);
	all->arg_len = ft_strlen(all->convert_str);
}
