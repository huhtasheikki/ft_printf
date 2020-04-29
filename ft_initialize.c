/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 11:16:55 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/29 11:55:20 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void		ft_init_flags_ft_ptr(t_all *all)
{
	all->flags_ft_ptr[0] = ft_flags_hash;
	all->flags_ft_ptr[1] = ft_flags_zero;
	all->flags_ft_ptr[2] = ft_flags_minus;
	all->flags_ft_ptr[3] = ft_flags_blank;
	all->flags_ft_ptr[4] = ft_flags_plus;
}

static void		ft_init_format_ft_ptr(t_all *all)
{
/*"diouxXDOUeEfFgGaACcSspn%"*/
/*"012345678901234567890123"*/
	all->format_ft_ptr[0] = &ft_signed_decimal;
	all->format_ft_ptr[1] = &ft_signed_decimal;
	all->format_ft_ptr[2] = &ft_unsigned_octal;
	all->format_ft_ptr[3] = &ft_unsigned_decimal;
	all->format_ft_ptr[4] = &ft_unsigned_hexa_lo;
	all->format_ft_ptr[5] = &ft_unsigned_hexa_up;
	all->format_ft_ptr[6] = &ft_long_int_decimal;
	all->format_ft_ptr[7] = &ft_long_int_octal;
	all->format_ft_ptr[8] = &ft_long_int_unsigned_decimal;
	all->format_ft_ptr[9] = &ft_double_e;
	all->format_ft_ptr[10] = &ft_double_E;
	all->format_ft_ptr[11] = &ft_float;
	all->format_ft_ptr[12] = &ft_float;
	all->format_ft_ptr[13] = &ft_double_ef;
	all->format_ft_ptr[14] = &ft_double_EF;
	all->format_ft_ptr[15] = &ft_double_a;
	all->format_ft_ptr[16] = &ft_double_A;
	all->format_ft_ptr[17] = &ft_unsigned_char_with_l;
	all->format_ft_ptr[18] = &ft_unsigned_char;
	all->format_ft_ptr[19] = &ft_str_with_l;
	all->format_ft_ptr[20] = &ft_str;
	all->format_ft_ptr[21] = &ft_void_ptr;
	all->format_ft_ptr[22] = &ft_number_char_so_far;
	all->format_ft_ptr[23] = &ft_percentage;
}

int		ft_initialize(t_all *all, const char *format)
{
	all->format_ptr = (char*)format;
	if (!(all->ready_print = ft_strnew(0)))
		return (0);
	ft_strncpy(all->flags_str, "#0- +", FLAGS + 1);
	ft_init_flags_ft_ptr(all);

	ft_strncpy(all->l_modifier_str, "hhlljtzqL", L_MODIFIER + 1);
	ft_strncpy(all->format_id_str, "diouxXDOUeEfFgGaACcSspn%", IDS + 1);
	ft_init_format_ft_ptr(all);
	return (1);
}
