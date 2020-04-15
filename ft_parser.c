/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 13:26:25 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/15 14:16:53 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void		ft_get_flags(t_all *all)
{
	int		i;

	i = 0;
	while (i < 5)
	{
		if (*all->format_ptr == all->flags_str[i])
		{
			all->flags[i] = 1;
			all->format_ptr++;
		}
		i++;
	}
}

void		ft_get_width(t_all *all)
{
	all->width = 0;
	if (*all->format_ptr == '*')
	{
		all->width = ft_get_asterisk(all);
		all->format_ptr++;
	}
	else
	{
		while (*all->format_ptr >= '0' && *all->format_ptr <= '9')
		{
			all->width = (all->width * 10) + get_nbr(*all->format_ptr);
			all->format_ptr++;
		}
	}
}

void		ft_get_precision(t_all *all)
{
	all->period = 0;
	all->precision = 0;
	if (*all->format_ptr == '.')
	{
		all->period = 1;
		all->format_ptr++;
		if (*all->format_ptr == '*')
		{
			all->precision = ft_get_asterisk(all);
			all->format_ptr++;
		}
		else
		{
			while (*all->format_ptr >= '0' && *all->format_ptr <= '9')
			{
				all->precision = (all->precision * 10) + get_nbr(*all->format_ptr);
				all->format_ptr++;
			}
		}
	}
}

void		ft_get_l_modifier(t_all *all)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (*all->format_ptr == all->l_modifier_str[i])
		{
			all->l_modifier[i] = 1;
			all->format_ptr++;
			break ;
		}
		i++;
	}
	if (all->l_modifier[0] == 1 && *all->format_ptr == 'h')
	{
		all->l_modifier[0] = 0;
		all->l_modifier[1] = 1;
		all->format_ptr++;
	}
	else if (all->l_modifier[2] == 1 && *all->format_ptr == 'l')
	{
		all->l_modifier[2] = 0;
		all->l_modifier[3] = 1;
		all->format_ptr++;
	}
}

void		ft_parser(t_all *all)
{
	int		i;

	i = 0;
	while (all->format_ptr)
	{
		ft_reset_variables(all);
		ft_str_cp_till_percent(all);
		if (all->format_ptr && *all->format_ptr == '%')
		{
			all->format_ptr++;
			ft_get_flags(all);
			ft_get_width(all);
			ft_get_precision(all);
			ft_get_l_modifier(all);
			ft_get_format_id(all);
			ft_arg_dioux(all);
			ft_variable_convert_to_str(all);
		}
		ft_free_parser(all);
	}
}
