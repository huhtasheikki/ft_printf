/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_variables.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:30:23 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/24 13:03:37 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_dioux(void *param)
{
	t_all	*all;
	int		arg;
	int		i;

	i = 0;
	all = (t_all*)param;
	arg = va_arg(all->ap, int);
	ft_l_modifier(all);
	ft_flags(all);
	ft_format_id(all);
	
	all->variable_str = ft_itoa_base(arg, base);
	ft_combine_strs(all->variable_str, all);
}

void	ft_signed_decimal(void *param)
{
	all->base = 10;
}

void	ft_unsigned_octal(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_unsigned_decimal(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_unsigned_hexa_lo(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_unsigned_hexa_up(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_long_int_decimal(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_long_int_octal(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_long_int_unsigned_decimal(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_double_e(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_double_E(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_float(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_double_ef(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_double_EF(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_double_a(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_double_A(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_unsigned_char_with_l(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_unsigned_char(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_str(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_str_with_l(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_void_ptr(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_number_char_so_far(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

void	ft_percentage(void *param)
{
	t_all	*all;
	
	all = (t_all*)param;
}

