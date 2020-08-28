/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bignumtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhuhtane <hhuhtane@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:31:18 by hhuhtane          #+#    #+#             */
/*   Updated: 2020/08/27 18:19:59 by hhuhtane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char		*mexp_test(long double f)
{
	char			*ret;
	t_ldbits		fb;

	fb.ld = f;
}
*/

char		*ft_bignumtoa(long double f)
{
	char			*ret_str;
	char			*temp_str;
	char			*temp2_str;
	long double		f_temp;
	long double		d_temp;
	long double		exp;

	exp = ft_pow(10, 14);
	f_temp = f / exp;
	temp_str = ft_uintmaxtoa_base((uintmax_t)f_temp, 10);
	ft_putendl(temp_str);
	d_temp = (unsigned long long)f_temp;
//	f_temp = ((f - (long double)((unsigned long long)f_temp * exp)));
	f_temp = (f_temp - d_temp) * exp;
	temp2_str = ft_uintmaxtoa_base((uintmax_t)f_temp, 10);
	ft_putendl(temp2_str);
	ret_str = ft_strjoin(temp_str, temp2_str);
	ft_memdel((void**)&temp_str);
	ft_memdel((void**)&temp2_str);
	return (ret_str);
}
