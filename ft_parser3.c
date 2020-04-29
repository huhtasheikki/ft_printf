/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 12:00:32 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/28 20:34:18 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format_id(t_all *all)
{
	int		i;

	i = 0;
	while (i < IDS)
	{
		if (all->format_id[i])
			all->format_ft_ptr[i](all);
		i++;
	}
}

void	ft_flags(t_all *all)
{
	int		i;

	i = 0;
	while (i < FLAGS)
	{
		if (all->flags[i] == 1)
			all->flags_ft_ptr[i](all);
		i++;
	}
}

void	ft_l_modifier(t_all *all)
{
	(void)all;
}

void	ft_field_width(t_all *all)
{
	if (all->arg_len < all->width)
	{
		(void)all;
	}
}

void	ft_precision(t_all *all)
{
	if (all->period)
	{
/* THESE ARE NOT DONE YET, like this or with function pointers? */
		if (ft_strchr("diouxX", all->format_char))
		{
//			precision_diouxx(all);
			(void)all;
		}
		else if (ft_strchr("aAeEfF", all->format_char))
		{
//			precision_aaeeff(all);
			(void)all;
		}
		else if (ft_strchr("gG", all->format_char))
		{
//			precision_gg(all);
			(void)all;
		}
		else if (all->format_char == 's')
		{
//			precision_s(all);
			(void)all;
		}
	}
}
