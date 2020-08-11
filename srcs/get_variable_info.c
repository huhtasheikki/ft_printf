/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:00:34 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/11 13:59:15 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_flags(t_all *all)
{
	int		i;

	i = 0;
	if (!(*all->format_ptr))
		return (0);
	while (i < FLAGS_SIZE)
	{
		if (*all->format_ptr == all->flags_str[i])
		{
			all->format_info = all->format_info | (1 << i);
			all->format_ptr++;
			return (1);
		}
		i++;
	}
	return (0);
}

static int		get_width(t_all *all)
{
	if (all->width || !(*all->format_ptr))
		return (0);
	if (*all->format_ptr > '0' && *all->format_ptr <= '9')
	{
		while (ft_isdigit(*all->format_ptr))
		{
			all->width = (all->width * 10) + get_nbr(*all->format_ptr);
			all->format_ptr++;
		}
	}
	if (*all->format_ptr == '*')
	{
		all->width = ft_width_asterisk(all);
		return (1);
	}
	if (all->width)
		return (1);
	return (0);
}

static int		get_precision(t_all *all)
{
	if ((all->format_info & (1 << PRECISION_INDEX)) || \
		*all->format_ptr != '.')
		return (0);
	all->format_info = all->format_info | (1 << PRECISION_INDEX);
	all->format_ptr++;
	if (!ft_isdigit(*all->format_ptr) && *all->format_ptr != '*')
	{
		all->precision = 0;
		return (1);
	}
	while (ft_isdigit(*all->format_ptr))
	{
		all->precision = (all->precision * 10) + get_nbr(*all->format_ptr);
		all->format_ptr++;
	}
	if (*all->format_ptr == '*')
		all->precision = ft_precision_asterisk(all);
	return (1);
}

static int		get_l_modifier(t_all *all)
{
	int			i;

	i = 0;
	if ((all->format_info & L_MOD_MASK) || !(*all->format_ptr))
		return (0);
	if (ft_strchr("hl", *all->format_ptr) && \
		all->format_ptr[0] == all->format_ptr[1])
	{
		if (*all->format_ptr == 'h')
			all->format_info = all->format_info | (1 << HH_INDEX);
		if (*all->format_ptr == 'l')
			all->format_info = all->format_info | (1 << LL_INDEX);
		all->format_ptr += 2;
	}
	else if (*all->format_ptr == 'h')
		all->format_info = all->format_info | (1 << H_INDEX);
	else if (*all->format_ptr == 'l')
		all->format_info = all->format_info | (1 << H_INDEX);
	else if (*all->format_ptr == 'L')
		all->format_info = all->format_info | (1 << UPL_INDEX);
	else
		return (0);
	return (1);
}

int				get_variable_info(t_all *all)
{
	int		mod;

	mod = 1;
	all->format_ptr++;
	ft_reset_format_info(all);
	while (mod)
	{
		mod = get_flags(all);
		mod += get_width(all);
		mod += get_precision(all);
	}
	get_l_modifier(all);
	if (!get_format_id(all))
		return (0);
	return (1);
}
