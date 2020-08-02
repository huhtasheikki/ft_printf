/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 20:53:19 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/02 13:17:55 by hhuhtane         ###   ########.fr       */
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
}

/* DOUBLE could be its own function */
void			get_double(t_all *all)
{
	all->arg_double = va_arg(all->args, double);
}

static int		ft_collect_arg(t_all *all)
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
	ft_putendl("before l_modifier start");
	ft_l_modifiers(all);
	return (1);
}

static int		get_format_id(t_all *all)
{
	int		i;

	i = 0;
	while (i < FORMAT_ID_SIZE)
	{
		if (*all->format_ptr == all->format_id_str[i])
		{
			all->format_id = 1 << i;
			all->format_ptr++;
			return (1);
		}
	}
	return (0);

/* DELETE THIS IF EVERYTHING WORKS, EARLY VERSION
	if (ft_strchr(FORMAT_ID, *all->format_ptr))
	{
		
		all->format_id = *all->format_ptr;
		return (1);
	}
	return (0);
*/
}

int				get_variable(t_all *all)
{
	if (!get_format_id(all))
		return (0);
//	if (get_format_id(all))
//		ft_collect_arg(all);
	ft_putendl("before collect");
	ft_collect_arg(all);
	ft_arg_convert(all);

	ft_putendl("STILL ALIVE");
	ft_putnbr(all->arg_int);
	ft_putendl(" arg_int");
	return (1); // make sure this is correct check
}
