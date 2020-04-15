/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 18:47:20 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/15 19:03:40 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags_minus(void *param)
{
	t_all	*all;
	char	format;

	all = (t_all*)param;
	format = all->format_char;
	all->padding_char = ' ';
	/* this should be only with field width KESKEN*/
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

void	ft_flags_plus(void *param)
{
	t_all	*all;
	char	format;

	all = (t_all*)param;
	format = all->format_char;
}

void	ft_flags_blank(void *param)
{
	t_all	*all;
	char	format;

	all = (t_all*)param;
	format = all->format_char;
}

void	ft_flags_hash(void *param)
{
	t_all	*all;
	char	format;

	all = (t_all*)param;
	format = all->format_char;
	if (!ft_strchr("cdinpsu", format))
	{
		if (format == 'o')
		{
			ft_memdel((void**)&all->variable_begin);
			all->variable_begin = ft_strnew(1);
			all->variable_begin[0] = '0';
		}
		ft_putendl("HASH");
	}
}
