/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 12:00:32 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/04/15 14:25:25 by hhuhtane         ###   ########.fr       */
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
