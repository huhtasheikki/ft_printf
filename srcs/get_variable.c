/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 20:53:19 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/06 19:38:41 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		get_diouxx(t_all *all)
{
	if ((all->format_id & DI_MASK))
	{
		all->arg_int = va_arg(all->args, int);
		all->arg_base = 10;
	}
	else
	{
		all->arg_int = va_arg(all->args, unsigned int);
		if ((all->format_id & (1 << O_INDEX)))
			all->arg_base = 8;
		else if ((all->format_id & (1 << U_INDEX)))
			all->arg_base = 10;
		else
			all->arg_base = 16;
	}
//	all->arg_len = ft_variable_len(all);
//	all->arg_len = ft_intlen_base(all->arg_int, all->arg_base);
}

void			get_double(t_all *all) // THIS FUNCTION TO GET DOUBLE
{
	all->arg_double = va_arg(all->args, double);
}

static int		ft_collect_var(t_all *all)
{
/* DIOUXX could be seperated as own function */
	if ((all->format_id & DIOUXX_MASK))
		get_diouxx(all);

/* DOUBLE could be its own function */
	if ((all->format_id & AAEEFFGG_MASK))
		get_double(all);

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
	ft_l_modifiers(all);
	ft_do_flags(all);
	ft_arg_convert(all);
	return (1); // make sure this is correct check
}
