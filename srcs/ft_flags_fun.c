/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:47:20 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/02 10:06:45 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*==================*/
/* '#' (hash) -FLAG */
/*==================*/
/*
The value should be converted to an ``alternate form''.
For c, d, i, n, p, s, and u conversions, this option has
no effect.  For o conversions, the precision of the number
is increased to force the first character of the output
string to a zero.  For x and X conversions, a non-zero
result has the string `0x' (or `0X' for X conversions)
prepended to it.  For a, A, e, E, f, F, g, and G conver-
sions, the result will always contain a decimal point,
even if no digits follow it (normally, a decimal point
appears in the results of those conversions only if a
digit follows).  For g and G conversions, trailing zeros
are not removed from the result as they would otherwise
be.
*/

void	ft_flag_hash(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if ((all->format_id & CDINPSU_MASK))
		return ;
	if ((all->format_id & (1 << O_INDEX)))
		all->prefix[0] = '0';
	else if ((all->format_id & (1 << X_INDEX)))
		ft_strcat(all->prefix, "0x");
	else if ((all->format_id & (1 << UPX_INDEX)))
		ft_strcat(all->prefix, "0X");
	else if ((all->format_id & AAEEFFGG_MASK))
	{
		ft_putendl("Do something");
			/* For a, A, e, E, f, F, g, and G conver-
			sions, the result will always contain a decimal
			point, even if no digits follow it (normally, a
			decimal point appears in the results of those con-
			versions only if a digit follows).  For g and G
			conversions, trailing zeros are not removed from
			the result as they would otherwise be.
			*/		
	}
	ft_putendl("HASH");
}

/*==================*/
/* '0' (zero) -FLAG */
/*==================*/
/*
Zero padding.  For all conversions except n, the converted
value is padded on the left with zeros rather than blanks.
If a precision is given with a numeric conversion (d, i,
o, u, i, x, and X), the 0 flag is ignored.
*/

void	ft_flag_zero(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if ((all->format_id & (1 << N_INDEX)))
		return ;
	if ((all->format_id & (DIOUXX_MASK)) && \
		(all->format_info & (1 << PRECISION_INDEX)))
		return ;
	if ((all->format_info & (1 << MINUS_INDEX))) // MINUS OVERRIDES
		return ;
	else
		all->padding_char = '0';
}

/*====================*/
/* '-' (minus) -FLAG  */
/*====================*/
/* A negative field width flag; the converted value is to be
left adjusted on the field boundary.  Except for n conver-
sions, the converted value is padded on the right with
blanks, rather than on the left with blanks or zeros.  A -
overrides a 0 if both are given.
*/

void	ft_flag_minus(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	all->padding_char = ' ';
	/* this should be only with field width KESKEN*/
}

/*===================*/
/* ' ' (space) -FLAG */
/*===================*/
/*
A blank should be left before a positive number produced
by a signed conversion (a, A, d, e, E, f, F, g, G, or i).
*/
void	ft_flag_space(void *param)
{
	t_all	*all;

	all = (t_all*)param;
	if ((all->format_id & DI_MASK))
	{
		if (all->arg_int >= 0)
			ft_strcpy(all->prefix, " ");
	}
	else if ((all->format_id & AAEEFFGG_MASK))
	{
		if (all->arg_double >= 0)
			ft_strcpy(all->prefix, " ");
	}
}

/*==================*/
/* '+' (plus) -FLAG */
/*==================*/
/*
A sign must always be placed before a number produced by a
signed conversion.  A + overrides a space if both are
used.
*/

void	ft_flag_plus(void *param)
{
	t_all	*all;

	all = (t_all*)param;

	if ((all->format_id & DI_MASK))
	{
		if (all->arg_int >= 0)
			ft_strcpy(all->prefix, "+");
	}
	else if ((all->format_id & AAEEFFGG_MASK))
	{
		if (all->arg_double >= 0)
			ft_strcpy(all->prefix, "+");
	}
}
