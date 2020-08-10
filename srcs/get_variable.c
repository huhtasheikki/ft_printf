/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 20:53:19 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/10 09:18:54 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		get_di(t_all *all)
{
	if ((all->format_info & (1 << H_INDEX)))
		all->arg_int = (short)va_arg(all->args, int);
	else if ((all->format_info & (1 << HH_INDEX)))
		all->arg_int = (signed char)va_arg(all->args, int);
	else if ((all->format_info & (1 << L_INDEX)))
		all->arg_int = (long int)va_arg(all->args, long int);
	else if ((all->format_info & (1 << LL_INDEX)))
		all->arg_int = (long long)va_arg(all->args, long long);
	else
		all->arg_int = va_arg(all->args, int);
	all->arg_base = 10;
}

static void		get_ouxx(t_all *all)
{
	if ((all->format_info & (1 << H_INDEX)))
		all->arg_uint = (unsigned short)va_arg(all->args, unsigned int);
	else if ((all->format_info & (1 << HH_INDEX)))
		all->arg_uint = (unsigned char)va_arg(all->args, unsigned int);
	else if ((all->format_info & (1 << L_INDEX)))
		all->arg_uint = va_arg(all->args, unsigned long);
	else if ((all->format_info & (1 << LL_INDEX)))
		all->arg_uint = va_arg(all->args, unsigned long long);
	else
		all->arg_uint = va_arg(all->args, unsigned int);
	if ((all->format_id & (1 << O_INDEX)))
		all->arg_base = 8;
	else if ((all->format_id & (1 << U_INDEX)))
		all->arg_base = 10;
	else
		all->arg_base = 16;
}

void			get_double(t_all *all) // THIS FUNCTION TO GET DOUBLE
{
	if ((all->format_info & (1 << UP_L_INDEX)))
		all->arg_double = va_arg(all->args, long double);
	else
		all->arg_double = va_arg(all->args, double);
//	all->convert_str = ft_ftoa(all->arg_double, all->precision);
}

static int		ft_collect_var(t_all *all)
{
/* Get if format is DI */
	if ((all->format_id & DI_MASK))
		get_di(all);

/* Get if format is OUXX */
	else if ((all->format_id & OUXX_MASK))
		get_ouxx(all);

/* DOUBLE could be its own function */
	else if ((all->format_id & AAEEFFGG_MASK))
		get_double(all);

	else if ((all->format_id & (1 << PERCENT_INDEX)))
		get_percent(all);

	else if ((all->format_id & (3 << UPC_INDEX)))
		get_char(all);

	else if ((all->format_id & (1 << S_INDEX)))
		get_str(all);

	else if ((all->format_id & (1 << P_INDEX)))
		get_ptr(all);
	//JNE
/*
	if (ft_strchr(FORMAT_ID, *all->format_ptr))
	{
		all->format_id = *all->format_ptr;
		all->format_ptr++;
		return (1);
	}
*/
	return (1);
}

int				get_variable(t_all *all)
{
//	if (!get_format_id(all))
//		return (0);
	ft_collect_var(all);
//	ft_l_modifiers(all); // don't need anymore, remove from Makefile as well
	ft_do_flags(all);
	ft_arg_convert(all);
	ft_precision(all);
	ft_variable_len(all);
//	ft_precision(all);
	combine_elements(all);
	ft_full_str_to_list(all);
	free(all->padding_str);
	free(all->convert_str);
	free(all->full_str);
	return (1); // make sure this is correct check
}
