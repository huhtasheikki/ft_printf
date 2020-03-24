/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 18:04:30 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/03/24 12:05:23 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_combine_strs(char *s1, t_all *all)
{
	size_t		len;
	char		*temp_ptr;

	if (!all->ready_print)
		len = ft_strlen(s1);
	else
		len = ft_strlen(all->ready_print) + ft_strlen(s1);
	temp_ptr = all->ready_print;
	if (!(all->ready_print = ft_memalloc(sizeof(char) * (len + 1))))
		exit (0);
	ft_strcat(all->ready_print, temp_ptr);
	ft_memdel((void**)&temp_ptr);
	ft_strcat(all->ready_print, s1);
	ft_memdel((void**)&s1);
}
