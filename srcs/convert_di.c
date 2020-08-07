/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 18:10:53 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/07 12:19:41 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static void		count_full_len(t_all *all)
{
	all->combined_len += ft_strlen(all->prefix);
	all->combined_len += ft_strlen(all->convert_str);
	ft_putnbr(all->combined_len);
	ft_putendl(" =============combined_len===========");
	if (all->combined_len < all->width)
	{
		all->padding_len = all->width - all->combined_len;
		all->combined_len = all->width;
	}
	ft_putnbr(all->combined_len);
	ft_putendl(" combined_len");
	ft_putnbr(all->width);
	ft_putendl(" width");
	ft_putnbr(all->padding_len);
	ft_putendl(" padding_len");
}
*/

void			combine_elements(t_all *all)
{
//	count_full_len(all); // DELETE THIS IF ft_variable_len works
	if (!(all->full_str = ft_strnew(all->combined_len + 1)))
		return ; // make as zero and change return value to int;
	if (all->padding_len > 0)
	{
		if (!(all->padding_str = ft_strnew(all->padding_len + 1)))
			return ; // make zero;
		ft_memset(all->padding_str, all->padding_char, all->padding_len);
		ft_strcat(all->full_str, all->padding_str);
	}
	ft_strcat(all->full_str, all->prefix);
	ft_strcat(all->full_str, all->convert_str);
}

void			convert_di(void *param)
{
	t_all		*all;

	all = (t_all*)param;
	if ((all->format_id & DI_MASK))
		all->convert_str = ft_itoa_base(all->arg_int, all->arg_base);
	else
		all->convert_str = ft_uitoa_base(all->arg_uint, all->arg_base);
	if ((all->format_id & (1 << UPX_INDEX)))
		ft_strtoupper(all->convert_str);
}
/* OLD */
/*
{
	t_all		*all;
	t_list		*txt_list;

	all = (t_all*)param;
//	ft_field_width(all); // if returns 0, error
//	padding_str = ft_padding(all); // DOES IT WORK??
	all->convert_str = ft_itoa_base(all->arg_int, all->arg_base);
	combine_elements(all);
//	if (!(all->format_info & FLAGS_MASK))
//	{
		txt_list = ft_lstnew(all->full_str, all->combined_len);
		ft_lstappend(&all->parsed_args, txt_list);
//	}
//	ft_putendl(arg_str);
}
*/
