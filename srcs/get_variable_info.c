/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:00:34 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/08 11:27:57 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_flags(t_all *all)
{
	int		i;

	i = 0;
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
	if (all->width)
		return 0;
	if (*all->format_ptr && *all->format_ptr > '0' && *all->format_ptr <= '9')
	{
		all->width = (all->width * 10) + get_nbr(*all->format_ptr);
		all->format_ptr++;
		while (*all->format_ptr && *all->format_ptr >= '0' && *all->format_ptr <= '9')
		{
			all->width = (all->width * 10) + get_nbr(*all->format_ptr);
			all->format_ptr++;
		}
	}
	if (all->width)
		return (1);
	else
		return (0);
}

static int		get_precision(t_all *all)
{
	if ((all->format_info & (1 << PRECISION_INDEX)))
		return 0;
	if (*all->format_ptr == '.')
	{
		all->format_info = all->format_info | (1 << PRECISION_INDEX);
		all->format_ptr++;
		if (*all->format_ptr == '*')
			return (0); // DO SOMETHING
		if (*all->format_ptr < '0' || *all->format_ptr > '9')
			all->precision = 0;
		else
		{
			while (all->format_ptr && *all->format_ptr >= '0' && \
					*all->format_ptr <= '9')  // keskes
			{
				all->precision = (all->precision * 10) + \
					get_nbr(*all->format_ptr);
				all->format_ptr++;
			}
		}
		return (1);
	}
	return (0);
}

static int		get_l_modifier(t_all *all)
{
	int			i;

	i = 0;
	if ((all->format_info & L_MOD_MASK))
		return 0;
	while (i < L_MOD_SIZE)
	{
		if (*all->format_ptr == all->l_modifier_str[i])
		{
			all->format_info = all->format_info | (1 << (i + L_MOD_INDEX));
			all->format_ptr++;
			if ((all->format_info & (1 << H_INDEX)) && *all->format_ptr == 'h')
			{
				all->format_info = all->format_info & ~(1 << H_INDEX);
				all->format_info = all->format_info | (1 << HH_INDEX);
				all->format_ptr++;
			}
			else if ((all->format_info & (1 << L_INDEX)) && *all->format_ptr == 'l')
			{
				all->format_info = all->format_info & ~(1 << L_INDEX);
				all->format_info = all->format_info | (1 << LL_INDEX);
				all->format_ptr++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void			get_variable_info(t_all *all)
{
	int		mod;

	mod = 1;

	if (*all->format_ptr == '%') //
		all->format_ptr++; //
	ft_reset_format_info(all);
	while (mod && all->format_ptr && !(all->format_id & (FORMAT_MASK)))
	{
		mod = get_flags(all);
		mod += get_width(all);
		mod += get_precision(all);
		mod += get_l_modifier(all);
	}
/* TO CHECK FORMAT_INFO
	int		i;
	i = 0;
	while (i < 14)
	{
		ft_putnbr(i);
		if ((all->format_info & (1 << i))) //
			ft_putendl(" ok!"); //
		else //
			ft_putendl(" FAIL!"); //
		i++;
	}
*/
	if (!get_format_id(all))
		return ; // change this to zero and make it error
//	get_variable(all); // if this 0 then invalid format
}
