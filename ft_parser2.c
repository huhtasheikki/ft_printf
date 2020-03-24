/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 16:14:42 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/23 18:18:36 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_test(void *param)
{
	(void)param;
}

void		ft_reset_variables(t_all *all)
{
	ft_bzero(all->flags, sizeof(int) * FLAGS);
	ft_bzero(all->l_modifier, sizeof(int) * L_MODIFIER);
	ft_bzero(all->format_id, sizeof(int) * IDS);
}

void		ft_variable_format_id(t_all *all)
{
	int		i;

	i = 0;
	while (i < IDS)
	{
		if (*all->format_ptr == all->format_id_str[i])
		{
			all->format_id[i] = 1;
			all->format_ptr++;
			break ;
		}
		i++;
	}
}

void		ft_variable_convert_to_str(t_all *all)
{
	int		i;

	i = 0;
	while (i < IDS)
	{
		if (all->format_id[i] == 1)
			all->format_ft_ptr[i](all);
		i++;
	}
}

int			ft_get_asterisk(t_all *all)
{
	int		asterisk;

	(void)all;
	asterisk = 0;
	return (asterisk);
}

void		ft_str_cp_till_percent(t_all *all)
{
	size_t		len;
	char		*text_str;
//	char		*temp_ptr;
	char		*percentage_ptr;

	if (!(percentage_ptr = ft_strchr(all->format_ptr, '%')))
		len = ft_strlen(all->format_ptr);
	else
		len = percentage_ptr - all->format_ptr;
	text_str = ft_strsub(all->format_ptr, 0, len);

	ft_combine_strs(text_str, all);
/*	
	len = ft_strlen(all->ready_print) + ft_strlen(text_str);
	temp_ptr = all->ready_print;
	if (!(all->ready_print = ft_memalloc(len + 1)))
		exit (0);
	ft_strcat(all->ready_print, temp_ptr);
	ft_memdel((void**)&temp_ptr);
	ft_strcat(all->ready_print, text_str);
	ft_memdel((void**)&text_str);
*/
	all->format_ptr = percentage_ptr;
//	}
}
