/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 11:34:10 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/24 13:01:55 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_l_modifier(t_all *all)
{
	size_t		i;

	i = 0;
	while (i < L_MODIFIER)
	{
		if (all->l_modifier[i])
			all->variable_str;
		i++;
	}
}

void	ft_flags(t_all *all)
{
	size_t		i;

	i = 0;
	while (i < FLAGS)
	{
		if (all->flags[i])
			all->flags_ft_ptr[i](all);
		i++;
	}
}

void	ft_format_id(t_all *all)
{
	size_t		i;

	i = 0;
	while (i < IDS)
	{
		if (all->flags[i])
			all->flags_ft_ptr[i](all);
		i++;
	}
}

