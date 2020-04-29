/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:47:20 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/17 16:07:14 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_hash(void *param)
{
	t_all	*all;
	char	format;

	all = (t_all*)param;
	format = all->format_char;
	if (!ft_strchr("cdinpsu", format))
	{
		if (format == 'o')
			all->prefix[0] = '0';
		else if (format == 'x')
			ft_strcat(all->prefix, "0x");
		else if (format == 'X')
			ft_strcat(all->prefix, "0X");
		else if (ft_strchr("aAeEfFgG", format))
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
}

void	ft_flags_zero(void *param)
{
	t_all	*all;
	char	format;

	all = (t_all*)param;
	format = all->format_char;
	if (format != 'n' && !(ft_strchr("diouixX", format) && all->period))
		all->padding_char = '0';
}

void	ft_flags_minus(void *param)
{
	t_all	*all;
	char	format;

	all = (t_all*)param;
	format = all->format_char;
	all->padding_char = ' ';
	/* this should be only with field width KESKEN*/
}

void	ft_flags_blank(void *param)
{
	t_all	*all;
	char	format;

	all = (t_all*)param;
	format = all->format_char;
	if (ft_strchr("aAdeEfFgGi", format))
	{
		if (all->arg_i >= 0)
			ft_strcpy(all->prefix, " ");
	}
}

void	ft_flags_plus(void *param)
{
	t_all	*all;
	char	format;

	all = (t_all*)param;
	format = all->format_char;
	if (ft_strchr("aAdeEfFgGi", format))
	{
		if (all->arg_i >= 0)
			ft_strcpy(all->prefix, "+");
	}
}
